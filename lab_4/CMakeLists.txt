cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME sfml_sample)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SFML_LIB_NAME SFML)

add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("${SFML_LIB_NAME}/include/")	# добавляем директории
include_directories("inc/")
link_directories("${SFML_LIB_NAME}/lib/")

add_executable("${PROJECT_NAME}" main.cpp 
#  src/Game.cpp src/Circle.cpp
)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics sfml-window sfml-system sfml-network sfml-audio
)