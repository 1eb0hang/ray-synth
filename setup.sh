#! /bin/sh 

if [ -d libs ]; then
    rm -rf libs
fi

mkdir -p libs/build

cd libs
. ../dependencies.sh # clones dependencies into libs folder

