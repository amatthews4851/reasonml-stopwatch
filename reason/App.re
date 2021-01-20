let getTimeToDisplay = (state: Reducer.state) =>
  Belt.Array.reduce(
    state.times,
    0.,
    (acc, timesTuple) => {
      let (startTime, endTime) = timesTuple;

      acc +. (endTime -. startTime);
    },
  )
  ->(value => value /. 1000.);

let padStringWithEndingZeros = str => {
  let split = Js.String.split(".", str);

  let bigNumber = Belt.Array.get(split, 0);
  let smallNumber = Belt.Array.get(split, 1);

  switch (bigNumber, smallNumber) {
  | (Some(bigNum), Some(smallNum)) when String.length(smallNum) === 2 =>
    bigNum ++ "." ++ smallNum ++ "0"
  | (Some(bigNum), Some(smallNum)) when String.length(smallNum) === 1 =>
    bigNum ++ "." ++ smallNum ++ "00"
  | (Some(bigNum), Some(smallNum)) when String.length(smallNum) === 0 =>
    bigNum ++ ".000"
  | (Some(bigNum), None) when bigNum === "0" => "0.000"
  | _ => str
  };
};

let getCurrentDateValue = () => Js.Date.make()->Js.Date.valueOf;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(Reducer.reducer, {times: [||], isRunning: false});

  React.useEffect1(
    () =>
      if (state.isRunning) {
        let interval =
          Js.Global.setInterval(
            () => getCurrentDateValue()->Tick->dispatch,
            10,
          );

        Some(() => Js.Global.clearInterval(interval));
      } else {
        None;
      },
    [|state.isRunning|],
  );

  <Background>
    <h1>
      {state
       ->getTimeToDisplay
       ->Js.Float.toString
       ->padStringWithEndingZeros
       ->(amount => amount ++ " seconds")
       ->ReasonReact.string}
    </h1>
    <div
      className={Css.style([Css.display(`flex), Css.flexDirection(`row)])}>
      <Button
        disabled={state.isRunning}
        onClick={_ => getCurrentDateValue()->Start->dispatch}>
        {ReasonReact.string("Start")}
      </Button>
      <Button
        disabled={!state.isRunning}
        onClick={_ => getCurrentDateValue()->Pause->dispatch}>
        {ReasonReact.string("Pause")}
      </Button>
      <Button disabled={state.isRunning} onClick={_ => dispatch(Reset)}>
        {ReasonReact.string("Reset")}
      </Button>
    </div>
  </Background>;
};
