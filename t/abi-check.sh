#!/bin/bash
set -e
set -x

RESULTS=${RESULTS:-.}
CHECK_DIR="${RESULTS}"/check
source_path="$(pwd)"

if [ $# -lt 2 ] ; then
  echo "Wrong number of parameters" >&2
  echo "Usage: $0 <old_version> <new_version> <git_source>" >&2
  echo "<git_source> defaults to \$(pwd)" >&2
  exit 1
fi

old_version="${1}"
new_version="${2}"

# drop "/" from branch names
old_version_norm="${old_version////_}"
new_version_norm="${new_version////_}"

rm -rf "${CHECK_DIR}"

mkdir -p "${CHECK_DIR}/source.$old_version_norm" \
  "${CHECK_DIR}/source.$new_version_norm"
cp -r "${source_path}"/.git "${CHECK_DIR}/source.$old_version_norm"
cp -r "${source_path}"/.git "${CHECK_DIR}/source.$new_version_norm"

# old version
(
  cd "${CHECK_DIR}/source.$old_version_norm"
  git checkout "$old_version" --force
  # work around for missing "lib" directory in git
  mkdir -p lib
  make
)
# new version
(
  cd "${CHECK_DIR}/source.$new_version_norm"
  git checkout -- .
  # work around for missing "lib" directory in git
  mkdir -p lib
  make
)

old_soversion="$(sed -ne 's/^VERSION *= *//p' "${CHECK_DIR}/source.$old_version_norm/Makefile")"
new_soversion="$(sed -ne 's/^VERSION *= *//p' "${CHECK_DIR}/source.$new_version_norm/Makefile")"

if [ "${old_soversion}" != "${new_soversion}" ]; then
  echo "The SOVERSION is different, skipping API/ABI tests."
  exit 0
fi

# generate config files
if [ -d "${CHECK_DIR}/source.${old_version_norm}/asn1-compiled" ]; then
  old_asn1="asn1-compiled"
else
  old_asn1="asn1"
fi
cat > "${CHECK_DIR}/${old_version_norm}.xml" << EOF
<version>
check/source.${old_version_norm}
</version>

<headers>
check/source.${old_version_norm}/include
</headers>

<libs>
check/source.${old_version_norm}/src/
</libs>

<include_paths>
check/source.${old_version_norm}/${old_asn1}
</include_paths>
EOF

if [ -d "${CHECK_DIR}/source.${new_version_norm}/asn1-compiled" ]; then
  new_asn1="asn1-compiled"
else
  new_asn1="asn1"
fi
cat > "${CHECK_DIR}/${new_version_norm}.xml" << EOF
<version>
check/source.${new_version_norm}
</version>

<headers>
check/source.${new_version_norm}/include
</headers>

<libs>
check/source.${new_version_norm}/src/
</libs>

<include_paths>
check/source.${new_version_norm}/${new_asn1}
</include_paths>
EOF

cd "${RESULTS}"

# NOTE: with >=1.99.13 we'll get -skip-internal-symbols=... + -skip-internal-types=...
abi-compliance-checker -l tcap \
  -d1 "check/${old_version_norm}.xml" -d2 "check/${new_version_norm}.xml"
