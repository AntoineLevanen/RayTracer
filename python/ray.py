import numpy as np
from numpy.linalg import norm


class Ray:

    def __init__(self, origin, direction, length=10000):
        self.origin = np.array(origin)
        self.direction = np.array(direction)
        self.length = length

    def intersection(self, objects):
        L = objects.origin - self.origin
        tc = np.dot(L, self.direction)
        if tc < 0.0:
            return False

        print(tc ** 2, norm(L) ** 2)
        d = np.sqrt(tc ** 2 - L ** 2)
        if (d > objects.raduis).all():
            return False
        t1c = np.sqrt(objects.raduis ** 2 - d ** 2)
        t1 = tc - t1c
        t2 = tc + t1c
        return True
