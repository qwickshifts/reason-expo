module Hooks = {
  [@mel.module "expo-linking"] [@mel.return nullable]
  external useURL: unit => option(string) = "useURL";
};

[@mel.module "expo-linking"]
external canOpenURL: string => Js.Promise.t(bool) = "canOpenURL";

