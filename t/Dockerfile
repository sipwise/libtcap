# DOCKER_NAME=libtcap-buster
FROM docker.mgm.sipwise.com/sipwise-buster:latest

# Important! Update this no-op ENV variable when this Dockerfile
# is updated with the current date. It will force refresh of all
# of the base images and things like `apt-get update` won't be using
# old cached versions when the Dockerfile is built.
ENV REFRESHED_AT 2019-06-28

RUN apt-get update && \
    apt-get install --assume-yes \
      abi-compliance-checker \
      git \
      && \
    apt-get clean

RUN echo './t/testrunner' >>/root/.bash_history

WORKDIR /code/

################################################################################
# Instructions for usage
# ----------------------
# When you want to build the base image from scratch (jump to the next section if you don't want to build yourself!):
# % docker build --tag="libtcap-buster" .
# % docker run --rm -i -t -v $(pwd)/..:/code:rw libtcap-buster:latest bash
#
# Use the existing docker image:
# % docker pull docker.mgm.sipwise.com/libtcap-buster
# % docker run --rm -i -t -v $(pwd)/..:/code:rw docker.mgm.sipwise.com/libtcap-buster:latest bash
#
# Inside docker (the command is in history, just press UP button):
#   ./t/testrunner
#
################################################################################
