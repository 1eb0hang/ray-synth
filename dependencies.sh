#! /bin/sh 

base_dir=`cd .. && pwd`

if test ! -d build/imgui/include ; then mkdir -p build/imgui/include ; fi
if test ! -d build/raylib ; then mkdir -p build/raylib ; fi

# imgui
git clone --recursive https://github.com/ocornut/imgui.git -b docking
ls imgui | grep .h | while read line; do  
  cp "imgui/${line}" "build/imgui/include/${line}"
done

ls imgui | grep .cpp | while read line; do  
  cp "imgui/${line}" "build/imgui/${line}"
done


# raylib-cpp
git clone --recursive https://github.com/RobLoach/raylib-cpp.git
if test ! -d temp/ ; then mkdir -p temp ; fi
cmake -S raylib-cpp -B temp
make --directory=temp
mv temp/_deps/raylib-build/raylib/* build/raylib/
rm -rf temp
