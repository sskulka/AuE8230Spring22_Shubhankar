# Install script for directory: /home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/sskulka/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/sskulka/catkin_ws/build/cpr_gazebo/cpr_race_modules/catkin_generated/installspace/gazebo_race_modules.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_race_modules/cmake" TYPE FILE FILES
    "/home/sskulka/catkin_ws/build/cpr_gazebo/cpr_race_modules/catkin_generated/installspace/gazebo_race_modulesConfig.cmake"
    "/home/sskulka/catkin_ws/build/cpr_gazebo/cpr_race_modules/catkin_generated/installspace/gazebo_race_modulesConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_race_modules" TYPE FILE FILES "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_race_modules" TYPE DIRECTORY FILES
    "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/docs"
    "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/launch"
    "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/meshes"
    "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/urdf"
    "/home/sskulka/catkin_ws/src/cpr_gazebo/cpr_race_modules/worlds"
    )
endif()

