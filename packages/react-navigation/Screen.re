type t;

[@mel.obj]
external make:
  (
    ~screen: [@mel.unwrap] [
               | `View(React.element)
               | `Navigator(CommonNavigation.t)
             ]
               =?,
    ~options: CommonNavigation.Options.t=?,
    ~linking: {.}=?, // TODO: define linking object
    unit
  ) =>
  t;
