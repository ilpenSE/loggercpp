# Stress Test

- This scripts are testing the logger with 1 million logs (you can change it via LOGS_COUNT macro)
- Running `make` will compile the stress.c and logger.h and spits out "app"
- Running `./app` will print out configurations, dropped logs, elapsed time and time per log (in nanoseconds)
- App accepts parameters: first parameter is the log policy which can be:
  -> `drop`, `block`, `priority_based`
  and second parameter is "will logger print to stderr?"
  -> `true` or `false`
- `benchmark.sh` will run the app with all possible parameters and append the results into results.txt file
- `testn.sh` will run `benchmark.sh` for specified times which can be specified with number parameter
like `testn.sh 10`. and it will clear the results.txt file and puts all the results to the file.
- `analyze.py` will do basic data analysis from results.txt file and generates 2x2 table where rows are policies and columns are stderr specifier. (Does avg, min, max, median, stdev)

# Results on my machine

- With 16 GB RAM and AMD Ryzen 5 5600 (6C/12T) CPU
- Compiled with GCC (without optimizations), on GNU/Linux:

```
+-------------------------+-------------------------+-------------------------+
| Single Threaded         | WITH stderr sink        | WITHOUT stderr sink     |
+-------------------------+-------------------------+-------------------------+
| Drop Policy             | (1000 runs)             | (1000 runs)             |
| Minimum                 | 2,580,975.00 logs/sec   | 8,634,043.00 logs/sec   |
| Maximum                 | 3,230,382.00 logs/sec   | 11,163,964.00 logs/sec  |
| Average                 | 2,953,149.73 logs/sec   | 10,496,672.40 logs/sec  |
| Median                  | 2,959,802.00 logs/sec   | 10,511,427.00 logs/sec  |
| Std Dev                 | 103,399.21 logs/sec     | 254,099.91 logs/sec     |
+-------------------------+-------------------------+-------------------------+
| Block Policy            | (1000 runs)             | (1000 runs)             |
| Minimum                 | 323,983.00 logs/sec     | 9,203,440.00 logs/sec   |
| Maximum                 | 3,176,460.00 logs/sec   | 10,937,473.00 logs/sec  |
| Average                 | 3,123,611.83 logs/sec   | 10,626,552.93 logs/sec  |
| Median                  | 3,132,678.00 logs/sec   | 10,642,191.50 logs/sec  |
| Std Dev                 | 91,834.92 logs/sec      | 139,600.51 logs/sec     |
+-------------------------+-------------------------+-------------------------+

+-------------------------+-------------------------+-------------------------+
| Multi Threaded          | WITH stderr sink        | WITHOUT stderr sink     |
+-------------------------+-------------------------+-------------------------+
| Drop Policy             | (1000 runs)             | (1000 runs)             |
| Minimum                 | 1,550,821.00 logs/sec   | 4,056,189.00 logs/sec   |
| Maximum                 | 3,650,525.00 logs/sec   | 10,020,402.00 logs/sec  |
| Average                 | 3,362,464.02 logs/sec   | 8,016,819.71 logs/sec   |
| Median                  | 3,475,533.00 logs/sec   | 8,034,407.00 logs/sec   |
| Std Dev                 | 354,351.53 logs/sec     | 820,383.60 logs/sec     |
+-------------------------+-------------------------+-------------------------+
| Block Policy            | (1000 runs)             | (1000 runs)             |
| Minimum                 | 368,533.00 logs/sec     | 7,537,867.00 logs/sec   |
| Maximum                 | 3,619,925.00 logs/sec   | 8,886,996.00 logs/sec   |
| Average                 | 3,492,315.83 logs/sec   | 8,212,761.55 logs/sec   |
| Median                  | 3,506,415.00 logs/sec   | 8,194,755.00 logs/sec   |
| Std Dev                 | 125,720.32 logs/sec     | 187,551.94 logs/sec     |
+-------------------------+-------------------------+-------------------------+
```

- NOTE: Block policy does not drop any log, producer will block the main thread
