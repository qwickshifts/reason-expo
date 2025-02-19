type t;

module Options = {
  type t;
};

type params;
[@mel.obj]
external params:
  (
    ~screen: string=?,
    ~params: [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))],
    unit
  ) =>
  params;
[@mel.send.pipe: t]
external navigate:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "navigate";

[@mel.send] external goBack: t => unit = "goBack";
