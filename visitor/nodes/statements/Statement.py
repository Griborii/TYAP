from abc import ABC, abstractmethod


class Statement(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass
