from abc import ABCMeta, abstractmethod

class Context(metaclass=ABCMeta):
    def __init__(self):
        self.__states = []
        self.__curState = None
        self.__stateInfo = 0

    def addState(self, state):
        if(state not in self.__states):
            self.__states.append(state)
    
    def changeState(self, state):
        if(state is None):
            return False
        if(self.__curState is None):
            print("初始化为：", state.getName())
        else:
            print("由", self.__curState.getName(), "变为", state.getName())
        self.__curState = state
        self.addState(state)
        return True

    def getState(self):
        return self.__curState

    def _setStateInfo(self, stateInfo):
        self.__stateInfo = stateInfo
        for state in self.__states:
            if(state.isMatch(stateInfo)):
                self.changeState(state)

    def _getStateInfo(self):
        return self.__stateInfo

class State:
    def __init__(self, name):
        self.__name = name

    def getName(self):
        return self.__name

    def isMatch(self, stateInfo):
        return False

    @abstractmethod
    def behavior(self, context):
        pass

class Water(Context):

    def __init__(self):
        super().__init__()
        self.addState(SolidState("固体"))
        self.addState(LiguidState("液态"))
        self.addState(GaseousState("气态"))
        self.setTemperature(25)

    def getTemperature(self):
        return self._getStateInfo()

    def setTemperature(self, temperature):
        self._setStateInfo(temperature)

    def riseTemperature(self, step):
        self.setTemperature(self.getTemperature() + step)

    def reduceTemperature(self, step):
        self.setTemperature(self.getTemperature() - step)

    def behavior(self):
        state = self.getState()
        if(isinstance(state, State)):
            state.behavior(self)



# 单例装饰器
def singleton(cls, *args, **kwargs):
    instance = {}

    def __singleton(*args, **kwargs):
        if cls not in instance:
            instance[cls] = cls(*args, **kwargs)
        return instance[cls]

    return __singleton


@singleton
class SolidState(State):

    def __init__(self, name):
        super().__init__(name)

    def isMatch(self, stateInfo): 
        return stateInfo < 0

    def behavior(self, context):
        print("我性格高冷，当前体温", context._getStateInfo(), "度")

@singleton
class LiguidState(State):

    def __init__(self, name):
        super().__init__(name)

    def isMatch(self, stateInfo):
        return (stateInfo >= 0 and stateInfo < 100)

    def behavior(self, context):
        print("我性格温和，当前体温", context._getStateInfo(), "度")

@singleton
class GaseousState(State):

    def __init__(self, name):
        super().__init__(name)

    def isMatch(self, stateInfo):
        return stateInfo >= 100

    def behavior(self, context):
        print("我性格热烈，当前温度", context._getStateInfo(), "度")


def testState():
    water = Water()
    water.behavior()
    water.setTemperature(-5)
    water.behavior()
    water.setTemperature(18)
    water.behavior()
    water.setTemperature(100)
    water.behavior()

testState()