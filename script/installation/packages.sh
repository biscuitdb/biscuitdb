#!/bin/bash

## =================================================================
## BISCUITDB PACKAGE INSTALLATION
##
## This script will install all the packages that are needed to
## build and run the DBMS.
##
## Supported environments:
##  * Ubuntu 20.04
##
## =================================================================

LINUX_BUILD_PACKAGES=(\
  "build-essential" \
  "clang" \
  "clang-format" \
  "clang-tidy" \
  "cmake" \
  "git" \
  "pkg-config" \
  "python3-pip" \
  "python-is-python3" \
  "ninja-build" \
  "wget" \
  "time" \
)
LINUX_TEST_PACKAGES=(\
  "curl" \
  "lsof" \
)

# Packages to be installed through pip3.
PYTHON_BUILD_PACKAGES=(
  "cpplint"
)
PYTHON_TEST_PACKAGES=(
)


## =================================================================


main() {
  set -o errexit

  INSTALL_TYPE="$1"
  if [ -z "$INSTALL_TYPE" ]; then
    INSTALL_TYPE="build"
  fi
  ALLOWED=("build" "test" "all")
  FOUND=0
  for key in "${ALLOWED[@]}"; do
    if [ "$key" == "$INSTALL_TYPE" ] ; then
      FOUND=1
    fi
  done
  if [ "$FOUND" = "0" ]; then
    echo "Invalid installation type '$INSTALL_TYPE'"
    echo -n "Allowed Values: "
    ( IFS=$' '; echo "${ALLOWED[*]}" )
    exit 1
  fi
  
  echo "PACKAGES WILL BE INSTALLED. THIS MAY BREAK YOUR EXISTING TOOLCHAIN."
  echo "YOU ACCEPT ALL RESPONSIBILITY BY PROCEEDING."
  echo
  echo "INSTALLATION TYPE: $INSTALL_TYPE"
  read -p "Proceed? [Y/n] : " yn
  case $yn in
      Y|y) install;;
      *) ;;
  esac

  echo "Script complete."
}

give_up() {
  set +x
  OS=$1
  VERSION=$2
  [ ! -z "$VERSION" ] && VERSION=" $VERSION"
  
  echo
  echo "Unsupported distribution '${OS}${VERSION}'"
  echo "Please contact our support team for additional help."
  echo "Be sure to include the contents of this message."
  echo "Platform: $(uname -a)"
  echo
  echo "(todo: add repo issues link)"
  echo
  exit 1
}

install() {
  set -x
  UNAME=$(uname | tr "[:lower:]" "[:upper:]" )
  VERSION=""

  case $UNAME in
    LINUX)
      DISTRO=$(cat /etc/os-release | grep '^ID=' | cut -d '=' -f 2 | tr "[:lower:]" "[:upper:]" | tr -d '"')
      VERSION=$(cat /etc/os-release | grep '^VERSION_ID=' | cut -d '"' -f 2)
      
      # We only support Ubuntu right now
      [ "$DISTRO" != "UBUNTU" ] && give_up $DISTRO $VERSION
      
      # Check Ubuntu version
      case $VERSION in
        20.04) install_linux ;;
        *) give_up $DISTRO $VERSION;;
      esac
      ;;

    *) give_up $UNAME $VERSION;;
  esac
}

install_pip() {
  curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
  python get-pip.py
  rm get-pip.py
}

install_linux() {
  # Update apt-get.
  apt-get -y update
  
  # Install packages. Note that word splitting is desired behavior.
  if [ "$INSTALL_TYPE" == "build" ] || [ "$INSTALL_TYPE" = "all" ]; then
    apt-get -y install $( IFS=$' '; echo "${LINUX_BUILD_PACKAGES[*]}" )
  fi
  if [ "$INSTALL_TYPE" == "test" ] || [ "$INSTALL_TYPE" = "all" ]; then
    apt-get -y install $( IFS=$' '; echo "${LINUX_TEST_PACKAGES[*]}" )
  fi

  if [ "$INSTALL_TYPE" == "build" ] || [ "$INSTALL_TYPE" = "all" ]; then
    for pkg in "${PYTHON_BUILD_PACKAGES[@]}"; do
      python3 -m pip show $pkg || python3 -m pip install $pkg
    done
  fi
  if [ "$INSTALL_TYPE" == "test" ] || [ "$INSTALL_TYPE" = "all" ]; then
    for pkg in "${PYTHON_TEST_PACKAGES[@]}"; do
      python3 -m pip show $pkg || python3 -m pip install $pkg
    done
  fi
}

main "$@"
