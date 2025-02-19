type t = Js.Dict.t(Screen.t);

module type ScreenNames = {
  type t;
  let all: list(t);
  let toString: t => string;
  let toScreen: t => Screen.t;
};

let make = (module Screens: ScreenNames) => {
  Screens.all
  |> List.map(screenEnum =>
       (Screens.toString(screenEnum), Screens.toScreen(screenEnum))
     )
  |> Js.Dict.fromList;
};

// Example to build type safe screens
//
// module Example = {
//   type t =
//     | Home
//     | Settings;
//
//   let all = [Home, Settings];
//   let toString =
//     fun
//     | Home => "Home"
//     | Settings => "Settings";
//
//   let toScreen =
//     fun
//     | Home => Screen.make()
//     | Settings => Screen.make();
// };
//
// let screens = make((module Example));
