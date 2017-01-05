# DOCKER_NAME=libtcap-jessie
FROM docker.mgm.sipwise.com/sipwise-jessie:latest

# Important! Update this no-op ENV variable when this Dockerfile
# is updated with the current date. It will force refresh of all
# of the base images and things like `apt-get update` won't be using
# old cached versions when the Dockerfile is built.
ENV REFRESHED_AT 2016-05-31

RUN apt-get update
RUN apt-get install --assume-yes git abi-compliance-checker

RUN echo './t/testrunner' >>/root/.bash_history

WORKDIR /code/

################################################################################
# Instructions for usage
# ----------------------
# When you want to build the base image from scratch (jump to the next section if you don't want to build yourself!):
# % docker build --tag="libtcap-jessie" .
# % docker run --rm -i -t -v $(pwd)/..:/code:rw libtcap-jessie:latest bash
#
# Use the existing docker image:
# % docker pull docker.mgm.sipwise.com/libtcap-jessie
# % docker run --rm -i -t -v $(pwd)/..:/code:rw docker.mgm.sipwise.com/libtcap-jessie:latest bash
#
# Inside docker (the command is in history, just press UP button):
#   ./t/testrunner
#
################################################################################
