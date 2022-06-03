## Build Docker image:
- `docker build . -t logowl_env`

## Create container to run the built binary:
- `docker run -it logowl_env`

## Run tester
- `./test/my_http_log_monitor_tester ./test/http_log.csv`

## Rebuild and run my_http_log_monitor_tester
I any changes are done in source code withing the container.
Rebuild and run tester using following commands.
- `cmake .`
- `make my_http_log_monitor_tester`
- `./test/my_http_log_monitor_tester ./test/http_log.csv`

## Code Reading Guidance
- Start reading from `test/my_http_log_monitor_tester.cpp`
- `owlib` is a library to use for implementing custom logowls
- `my_http_log_monitor` uses `owlib` to implement concrete monitor for given log format.

## Code/Design Improvements
- Implement Alert abstract class and extend Owl to have mechanism of generating Alerts
- Add some more validations and exceptions
- Implement ListenCommands method in Owl
- Add time based Rule trigger and not on log line read
- Add unit tests
- Make code memory leakproof
- Make data members and variables consistent