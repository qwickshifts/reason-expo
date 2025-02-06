type permissionExpiration; // "never" | float

type permissionStatus = [ | `denied | `granted | `undetermined];

type permissionResponse = {
  canAskAgain: bool,
  expires: permissionExpiration,
  granted: bool,
  status: permissionStatus,
};

type permissionDetailsLocationIOS = {
  scope: [ | `always | `whenInUse | `none],
};

type permissionDetailsLocationAndroid = {scope: [ | `fine | `coarse | `none]};

type locationPermissionResponse = {
  ios: permissionDetailsLocationIOS,
  android: permissionDetailsLocationAndroid,
  canAskAgain: bool,
  expires: permissionExpiration,
  granted: bool,
  status: permissionStatus,
};

let isPermissionGranted = ({granted, _}: locationPermissionResponse) => granted;

type options;

[@mel.obj]
external options:
  (
    ~accuracy: [@mel.int] [
                 | [@mel.as 1] `lowest
                 | [@mel.as 2] `low
                 | [@mel.as 3] `balanced
                 | [@mel.as 4] `high
                 | [@mel.as 5] `highest
                 | [@mel.as 6] `bestForNavigation
               ]
                 =?,
    ~distanceInterval: float=?,
    ~mayShowUserSettingsDialog: bool=?,
    ~timeInterval: int=?,
    unit
  ) =>
  options;

[@deriving (getSet, jsProperties)]
type tCoords = {
  [@mel.optional]
  accuracy: option(float),
  [@mel.optional]
  altitude: option(float),
  [@mel.optional]
  altitudeAccuracy: option(float),
  [@mel.optional]
  heading: option(float),
  latitude: float,
  longitude: float,
  [@mel.optional]
  speed: option(float),
};

type t = {
  coords: tCoords,
  mocked: option(bool),
  timestamp: int,
};

[@mel.module "expo-location"]
external useForegroundPermissions:
  unit =>
  (
    Js.Null.t(locationPermissionResponse),
    unit => Js.Promise.t(locationPermissionResponse),
    unit => Js.Promise.t(locationPermissionResponse),
  ) =
  "useForegroundPermissions";

[@mel.module "expo-location"]
external getForegroundPermissionsAsync:
  unit => Js.Promise.t(locationPermissionResponse) =
  "getForegroundPermissionsAsync";

[@mel.module "expo-location"]
external getCurrentPositionAsync: options => Js.Promise.t(t) =
  "getCurrentPositionAsync";

[@mel.module "expo-location"]
external requestForegroundPermissionsAsync:
  unit => Js.Promise.t(locationPermissionResponse) =
  "requestForegroundPermissionsAsync";
