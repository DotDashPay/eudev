#!/bin/sh

autoreconf -f -i -s

# @sarietta: there are some dependencies to build the man pages for this library
# eudev that are not part of any other library's dependencies.
# We don't need the man pages and these dependencies are so specific.
# cd man
# ./make.sh
