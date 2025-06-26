cmake_minimum_required(VERSION 3.10)
project(abb_irb7600)

find_package(ament_cmake REQUIRED)
find_package(xacro REQUIRED)

install(DIRECTORY description/
  DESTINATION share/${PROJECT_NAME}/description
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
