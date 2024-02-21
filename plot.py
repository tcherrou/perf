import matplotlib.pyplot as plt

# High contention issue
# Create flamegraph
times = open("times.csv").read()
duration = 10

times = times.split("\n")
print(times)
tp = [int(ops)/duration for ops in times ]
plt.plot(range(1,5),tp)

plt.show()