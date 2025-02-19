include CommonNavigation;

module Options = {
  type t = Options.t;
  [@mel.obj]
  external make:
    (
      ~title: string=?,
      ~tabBarLabel: string=?,
      ~tabBarShowLabel: bool=?,
      ~tabBarLabelPosition: [
                              | [@mel.as "below-icon"] `belowIcon
                              | [@mel.as "beside-icon"] `besideIcon
                            ]
                              =?,
      ~tabBarLabelStyle: ReactNative.Style.t=?,
      ~tabBarIcon: {
                     .
                     "focused": bool,
                     "color": ReactNative.Color.t,
                     "size": float,
                   } =>
                   React.element
                     =?,
      ~tabBarIconStyle: ReactNative.Style.t=?,
      ~tabBarBadge: string=?,
      ~tabBarBadgeStyle: ReactNative.Style.t=?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarButton: unit => React.element=?,
      ~tabBarButtonTestID: string=?,
      ~tabBarActiveTintColor: ReactNative.Color.t=?,
      ~tabBarInactiveTintColor: ReactNative.Color.t=?,
      ~tabBarActiveBackgroundColor: ReactNative.Color.t=?,
      ~tabBarInactiveBackgroundColor: ReactNative.Color.t=?,
      ~tabBarHideOnKeyboard: bool=?,
      ~tabBarItemStyle: ReactNative.Style.t=?,
      ~tabBarStyle: ReactNative.Style.t=?,
      ~tabBarBackground: unit => React.element=?,
      ~tabBarPosition: [ | `bottom | `top | `left | `right]=?,
      ~tabBarVariant: [ | `uikit | `material]=?,
      ~_lazy: bool=?,
      ~freezeOnBlur: bool=?,
      ~popToTopOnBlur: bool=?,
      ~sceneStyle: ReactNative.Style.t=?,
      // header options
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
               }
                 =?,
      ~headerStyle: ReactNative.Style.t=?,
      ~headerShown: bool=?,
      unit
    ) =>
    t;
};

[@mel.send.pipe: t]
external jumpTo:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "jumpTo";
