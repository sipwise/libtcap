# DOCKER_NAME=libtcap-stretch
FROM docker.mgm.sipwise.com/sipwise-stretch:latest

# Important! Update this no-op ENV variable when this Dockerfile
# is updated with the current date. It will force refresh of all
# of the base images and things like `apt-get update` won't be using
# old cached versions when the Dockerfile is built.
ENV REFRESHED_AT 2017-09-25

RUN apt-get update
RUN apt-get install --assume-yes git abi-compliance-checker

RUN echo './t/testrunner' >>/root/.bash_history

WORKDIR /code/

################################################################################
# Instructions for usage
# ----------------------
# When you want to build the base image from scratch (jump to the next section if you don't want to build yourself!):
# % docker build --tag="libtcap-stretch" .
# % docker run --rm -i -t -v $(pwd)/..:/code:rw libtcap-stretch:latest bash
#
# Use the existing docker image:
# % docker pull docker.mgm.sipwise.com/libtcap-stretch
# % docker run --rm -i -t -v $(pwd)/..:/code:rw docker.mgm.sipwise.com/libtcap-stretch:latest bash
#
# Inside docker (the command is in history, just press UP button):
#   ./t/testrunner
#
################################################################################
