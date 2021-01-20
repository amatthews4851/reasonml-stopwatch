module Styles = {
  open Css;
  let background =
    style([
      backgroundColor(hex("aff")),
      display(`flex),
      flexDirection(`column),
      justifyContent(`flexStart),
      alignItems(`center),
      height(vh(100.)),
      width(vw(100.)),
      padding(rem(2.)),
    ]);
};

[@react.component]
let make = (~children) => {
  <div className=Styles.background> children </div>;
};
