module Styles = {
  open Css;

  let button = disabled => {
    let baseStyles = [
      borderRadius(px(5)),
      padding(px(10)),
      borderWidth(px(0)),
      backgroundColor(hex("#fff")),
      margin(em(1.)),
      boxShadow(
        Shadow.box(~y=px(3), ~blur=px(5), rgba(0, 0, 0, `num(0.3))),
      ),
      active([outline(px(0), `solid, black)]),
    ];

    if (disabled) {
      style(List.concat([baseStyles, [cursor(`default)]]));
    } else {
      style(
        List.concat([
          baseStyles,
          [
            cursor(pointer),
            hover([
              boxShadow(
                Shadow.box(
                  ~y=px(5),
                  ~blur=px(8),
                  rgba(0, 0, 0, `num(0.3)),
                ),
              ),
            ]),
          ],
        ]),
      );
    };
  };
};

[@react.component]
let make = (~children, ~onClick, ~disabled) => {
  <button onClick disabled className={Styles.button(disabled)}>
    children
  </button>;
};
