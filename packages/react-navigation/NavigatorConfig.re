type t;

[@mel.obj]
external make:
  (
    ~id: string=?,
    ~initialRouteName: string=?,
    ~layout: 'props => React.element=?,
    ~screenOptions: CommonNavigation.Options.t=?,
    ~screens: Screens.t,
    ~groups: Groups.t('a)=?, // TODO: actually write real Groups bindings
    unit
  ) =>
  t;
