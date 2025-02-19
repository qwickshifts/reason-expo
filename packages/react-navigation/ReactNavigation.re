module DrawerNavigation = DrawerNavigation;
module StackNavigation = StackNavigation;
module TabNavigation = TabNavigation;
module Route = Route;
module Screens = Screens;

[@mel.module "@react-navigation/native"]
external useNavigation: unit => CommonNavigation.t = "useNavigation";

[@mel.module "@react-navigation/native"]
external useRoute: unit => Route.t = "useRoute";

[@mel.module "@react-navigation/stack"]
external createStackNavigator: NavigatorConfig.t => StackNavigation.t =
  "createStackNavigator";

[@mel.module "@react-navigation/bottom-tabs"]
external createBottomTabNavigator: NavigatorConfig.t => TabNavigation.t =
  "createBottomTabNavigator";

[@mel.module "@react-navigation/drawer"]
external createDrawerNavigator: NavigatorConfig.t => DrawerNavigation.t =
  "createDrawerNavigator";

[@mel.module "@react-navigation/elements"]
external useHeaderHeight: unit => float = "useHeaderHeight";

[@mel.module "@react-navigation/native"]
external createStaticNavigation: CommonNavigation.t => React.element =
  "createStaticNavigation";
