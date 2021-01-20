type state = {
  times: array((float, float)),
  isRunning: bool,
};

type action =
  | Start(float)
  | Pause(float)
  | Tick(float)
  | Reset;

let reducer = (state, action) =>
  switch (action) {
  | Start(startTime) => {
      times: Array.concat([state.times, [|(startTime, startTime)|]]),
      isRunning: true,
    }
  | Pause(pauseTime) =>
    let lastIndex = Array.length(state.times) - 1;
    let (lastStartTime, _) = state.times[lastIndex];

    {
      times:
        Utils.updateElementInArray(
          state.times,
          lastIndex,
          (lastStartTime, pauseTime),
        ),
      isRunning: false,
    };
  | Tick(newTime) =>
    let lastIndex = Array.length(state.times) - 1;
    let (lastStartTime, _) = state.times[lastIndex];

    {
      ...state,
      times:
        Utils.updateElementInArray(
          state.times,
          lastIndex,
          (lastStartTime, newTime),
        ),
    };

  | Reset => {isRunning: false, times: [||]}
  };
