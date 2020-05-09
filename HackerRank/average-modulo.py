class Rat:
    def __init__(self, num: int, den: int):
        self.num = num
        self.den = den
        self.reduce()

    def __add__(self, other: Rat):
        return Rat(self.num * other.den + other.num * self.den,
                   self.den * other.den)
    def __radd__(self, other):
        self.num = self.num * other.den + other.num * self.den
        self.den = self.den * other.den
        self.reduce()

    def __sub__(self, other: Rat):
        return Rat(self.num * other.den - other.num * self.den,
                   self.den * other.den)
    def __rsub__(self, other):
        self.num = self.num * other.den - other.num * self.den
        self.den = self.den * other.den
        self.reduce()

    def __mul__(self, other: Rat):
        return Rat(self.num * other.num,
                   self.den * other.den)
    def __rmul__(self, other):
        self.num = self.num * other.num
        self.den = self.den * other.den
        self.reduce()

    def __truediv__(self, other: Rat):
        return Rat(self.num * other.den,
                   self.den * other.num)
    def __rtruediv__(self, other):
        self.num = self.num * other.den
        self.den = self.den * other.num
        self.reduce()

    def __eq__(self, other):
        return self.num == other.num and self.den == other.den
    def __gt__(self, other):
        return self.num*other.den < other.num*self.den
    def __ge__(self, other):
        return self > other or self == other
    def __lt__(self, other):
        return not (self >= other)
    def __le__(self, other):
        return not (self > other)

    @staticmethod
    def gcd(a: int, b: int):
        if b == 0:
            return a
        else:
            return Rat.gcd(b, a % b)

    def reduce(self):
        n = -self.num if self.num < 0 else self.num
        d = self.den

        gcd = Rat.gcd(n, d)
        self.num /= gcd
        self.den /= gcd

T = int(input())
for _ in range(T):
  N, p, k = list(map(int, input().split()))
  a = list(map(int, input().split()))
  

