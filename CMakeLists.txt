cmake_minimum_required(VERSION 3.22)
project(Lab1Hammurabi)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab1Hammurabi)
include_directories(Lab1Hammurabi/Loggers)
include_directories(Lab1Hammurabi/Misc)
include_directories(Lab1Hammurabi/Round)
include_directories(Lab1Hammurabi/RoundActions)

add_executable(Lab1Hammurabi
        Lab1Hammurabi/Loggers/IGameLogger.cpp
        Lab1Hammurabi/Loggers/IGameLogger.h
        Lab1Hammurabi/Loggers/TestGameLogger.cpp
        Lab1Hammurabi/Loggers/TestGameLogger.h
        Lab1Hammurabi/Misc/IntMinMax.h
        Lab1Hammurabi/Round/Round.cpp
        Lab1Hammurabi/Round/Round.h
        Lab1Hammurabi/Round/RoundResultEnum.h
        Lab1Hammurabi/Round/RoundSharedInfo.h
        Lab1Hammurabi/RoundActions/ActionResult.cpp
        Lab1Hammurabi/RoundActions/ActionResult.h
        Lab1Hammurabi/RoundActions/ActionResultBuilder.cpp
        Lab1Hammurabi/RoundActions/ActionResultBuilder.h
        Lab1Hammurabi/RoundActions/CitizenIncome.cpp
        Lab1Hammurabi/RoundActions/CitizenIncome.h
        Lab1Hammurabi/RoundActions/CitizenWheatConsumptionAction.cpp
        Lab1Hammurabi/RoundActions/CitizenWheatConsumptionAction.h
        Lab1Hammurabi/RoundActions/IRoundAction.cpp
        Lab1Hammurabi/RoundActions/IRoundAction.h
        Lab1Hammurabi/RoundActions/PlaqueAction.cpp
        Lab1Hammurabi/RoundActions/PlaqueAction.h
        Lab1Hammurabi/RoundActions/RatsAction.cpp
        Lab1Hammurabi/RoundActions/RatsAction.h
        Lab1Hammurabi/RoundActions/WheatIncomeAction.cpp
        Lab1Hammurabi/RoundActions/WheatIncomeAction.h
        Lab1Hammurabi/City.cpp
        Lab1Hammurabi/City.h
        Lab1Hammurabi/HammurabiConfig.h
        Lab1Hammurabi/MainLab1Hammurabi.cpp)
