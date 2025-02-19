include CommonNavigation;

module Options = {
  type t = Options.t;
  [@mel.obj]
  external make:
    (
      ~title: string=?,
      ~_lazy: bool=?,
      ~drawerLabel: string=?,
      ~drawerIcon: {
                     .
                     focused: bool,
                     color: string,
                     size: int,
                   } =>
                   React.element
                     =?,
      ~drawerActiveTintColor: ReactNative.Color.t=?,
      ~drawerActiveBackgroundColor: ReactNative.Color.t=?,
      ~drawerInactiveTintColor: ReactNative.Color.t=?,
      ~drawerInactiveBackgroundColor: ReactNative.Color.t=?,
      ~drawerItemStyle: ReactNative.Style.t=?,
      ~drawerLabelStyle: ReactNative.Style.t=?,
      ~drawerContentContainerStyle: ReactNative.Style.t=?,
      ~drawerContentStyle: ReactNative.Style.t=?,
      ~drawerStyle: ReactNative.Style.t=?,
      ~drawerPosition: [ | `left | `right]=?,
      ~drawerType: [ | `front | `back | `slide | `permanent]=?,
      ~drawerHideStatusBarOnOpen: bool=?,
      ~drawerStatusBarAnimation: [ | `slide | `fade | `none]=?,
      ~overlayColor: ReactNative.Color.t=?,
      ~sceneStyle: ReactNative.Style.t=?,
      // ~configureGestureHandler:  needs gesture handler bindings
      ~swipeEnabled: bool=?,
      ~swipeEdgeWidth: int=?,
      ~swipeMinDistance: int=?,
      ~keyboardDismissMode: [ | [@mel.as "on-drag"] `onDrag | `none]=?,
      ~freezeOnBlur: bool=?,
      ~popToTopOnBlur: bool=?,
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

[@mel.send] external openDrawer: t => unit = "openDrawer";

[@mel.send] external closeDrawer: t => unit = "closeDrawer";

[@mel.send] external toggleDrawer: t => unit = "toggleDrawer";

[@mel.send.pipe: t]
external jumpTo:
  (string, [@mel.unwrap] [ | `Nested(params) | `Terminal(Js.t('a))]) => unit =
  "jumpTo";
