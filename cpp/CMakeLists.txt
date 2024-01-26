cmake_minimum_required(VERSION 3.0)

project(ray_tracer)

# Crée des variables avec les fichiers à compiler
set(SRCS
    ray_tracer/main_ray_tracer.cpp
    )
    
set(HEADERS
    ray_tracer/vec3.h
    )

# On indique que l'on veut un exécutable "hello" 
# compilé à partir des fichiers décrits par les 
# variables SRCS et HEADERS
add_executable(ray_tracer ${SRCS} ${HEADERS})