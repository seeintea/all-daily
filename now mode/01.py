#!/usr/bin/env python
from abc import ABCMeta, abstractmethod

class WaterHeater:
    def __init__(self):
        self.__observers = []
        self.__temperature = 25

    def getTemperature(self):
        return self.__temperature

    def setTemperature(self, temperature):
        self.__temperature = temperature
        print("now temperature :" + str(self.__temperature) + "C")
        self.notifies()

    def addObserver(self, observer):
        self.__observers.append(observer)

    def notifies(self):
        for o in self.__observers:
            o.update(self)

class Observer(metaclass=ABCMeta):
    @abstractmethod
    def update(self, waterHeater):
        pass

class WashingMode(Observer):
    def update(self, waterHeater):
        if waterHeater.getTemperature() >= 50 and waterHeater.getTemperature() < 70:
            print("can use washingMode")

class DrinkingMode(Observer):
    def update(self, waterHeater):
        if waterHeater.getTemperature() >= 100:
            print("can use drinkingMode")

def testWaterHeader():
    heater = WaterHeater()
    washingMode = WashingMode()
    drinkingMode = DrinkingMode()
    heater.addObserver(washingMode)
    heater.addObserver(drinkingMode)
    heater.setTemperature(40)
    heater.setTemperature(50)
    heater.setTemperature(100)

testWaterHeader() 