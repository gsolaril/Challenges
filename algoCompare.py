import sys, math, time, matplotlib.pyplot
from math import log10, exp, sqrt
URL = "https://drive.google.com/uc?id="
ID = "1yBlp28E_aSiuegP3uXKph3lU3uDyHsJR"
matplotlib.pyplot.style.use(URL + ID)

def algoCompare(methods, span, logt = False, **kwargs):

    sys.stdout.write(f"\rIteration: {0}")
    assert isinstance(methods, dict)
    assert isinstance(span, int)
    steps = list(range(1, span + 1))
    nm, delay = len(methods), dict()
    for s in methods: delay[s] = []
    DT = xT = 0
    for n in steps:
        T = time.time()
        for s, f in methods.items():
            t = time.time()
            result = f(n, **kwargs)
            dt = time.time() - t
            if logt:
                try: dt = log10(dt)
                except: dt = -6
            delay[s].append(dt)
        s1 = f"\rIteration: {n} | "
        if DT != 0:
            xT = ((time.time() - T)/DT)**2
        DT = (time.time() - T)
        s2 = "Next (Log): %.2f seg" % (xT*DT)
        sys.stdout.write(s1 + s2)
        sys.stdout.flush()
    Figure, Axes = matplotlib.pyplot.subplots()
    Figure.set_figwidth(16)
    for n, s in enumerate(delay):
        c = [0, (2 - n/nm)/2, (1 + n/nm)/2]
        Axes.plot(steps, delay[s], color = c, label = s, lw = 3)
        Axes.set_ylabel(logt*"Log "+ "secs", fontweight = "bold")
        Axes.set_xticks(ticks = ([0] + steps)[:: len(steps)//20])
        Axes.legend(fontsize = 12)
    return Figure, Axes

if (__name__ == "__main__"):
    methods = {"Series": lambda x: sum(range(x)),
               "Formula": lambda x: x*(x - 1)/2}
    Figure, Axes = algoCompare(methods = methods, span = 1000)
    Figure.savefig("algoCompareExample.jpg")