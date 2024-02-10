from abc import ABC, abstractmethod


class Expression(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass
