include CommonNavigation;

module Options = {
  type t = Options.t;
  [@mel.obj]
  external make:
    (
      ~title: string=?,
      ~cardShadowEnabled: bool=?,
      ~cardOverlayEnabled: bool=?,
      ~cardOverlay: unit => React.element=?,
      ~cardStyle: ReactNative.Style.t=?,
      ~presentation: [ | `card | `modal | `transparentModal]=?,
      ~animationTypeForReplace: [ | `push | `pop]=?,
      ~gestureEnabled: bool=?,
      ~gestureResponseDistance: int=?,
      ~gestureVelocityImpact: float=?,
      ~gestureDirection: [
                           | `default
                           | `fade
                           | `fade_from_bottom
                           | `fade_from_right
                           | `reveal_from_bottom
                           | `scale_from_center
                           | `slide_from_right
                           | `slide_from_left
                           | `slide_from_bottom
                           | `none
                         ]
                           =?,
      ~transitionSpec: [
                         | `default
                         | `fade
                         | `fade_from_bottom
                         | `fade_from_right
                         | `reveal_from_bottom
                         | `scale_from_center
                         | `slide_from_right
                         | `slide_from_left
                         | `slide_from_bottom
                         | `none
                       ]
                         =?,
      ~cardStyleInterpolator: [
                                | `default
                                | `fade
                                | `fade_from_bottom
                                | `fade_from_right
                                | `reveal_from_bottom
                                | `scale_from_center
                                | `slide_from_right
                                | `slide_from_left
                                | `slide_from_bottom
                                | `none
                              ]
                                =?,
      ~headerStyleInterpolator: [
                                  | `default
                                  | `fade
                                  | `fade_from_bottom
                                  | `fade_from_right
                                  | `reveal_from_bottom
                                  | `scale_from_center
                                  | `slide_from_right
                                  | `slide_from_left
                                  | `slide_from_bottom
                                  | `none
                                ]
                                  =?,
      ~keyboardHandlingEnabled: bool=?,
      ~detachPreviousScreen: bool=?,
      ~freezeOnBlur: bool=?,
      //header options
      ~header: {
                 .
                 "navigation": CommonNavigation.t,
                 "route": Route.t,
                 "options": CommonNavigation.Options.t,
                 "layout": {
                   .
                   "height": int,
                   "width": int,
                 },
               } =>
               React.element
                 =?,
      ~headerStyle: ReactNative.Style.t=?,
      ~headerMode: [ | `float | `screen]=?,
      ~headerShown: bool=?,
      ~headerBackAllowFontScaling: bool=?,
      ~headerBackAccessibilityLabel: string=?,
      ~headerBackImage: {. "tintColor": ReactNative.Color.t} => React.element
                          =?,
      ~headerBackTitle: string=?,
      ~headerTruncatedBackTitle: string=?,
      ~headerBackButtonDisplayMode: [ | `default | `generic | `minimal]=?,
      ~headerBackTitleStyle: ReactNative.Style.t=?,
      unit
    ) =>
    t;
};
[@mel.send.pipe: t]
external replace:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "replace";

[@mel.send.pipe: t]
external push:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "push";

[@mel.send.pipe: t] external pop: int => unit = "pop";

[@mel.send.pipe: t]
external popTo:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "popTo";

[@mel.send] external popToTop: t => unit = "popToTop";
