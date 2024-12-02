// Enums
[@deriving jsConverter]
type androidAudioContentType =
  | Unknown
  | Speech
  | Music
  | Movie
  | Sonification;

[@deriving jsConverter]
type androidAudioUsage =
  | Unknown
  | Media
  | VoiceCommunication
  | VoiceCommunicationSignalling
  | Alarm
  | Notification
  | NotificationRingtone
  | NotificationCommunicationRequest
  | NotificationCommunicationInstant
  | NotificationCommunicationDelayed
  | NotificationEvent
  | AssistanceAccessibility
  | AssistanceNavigationGuidance
  | AssistanceSonification
  | Game;

[@deriving jsConverter]
type androidImportance =
  | Unknown
  | Unspecified
  | None
  | Min
  | Low
  | Default
  | High
  | Max;

[@deriving jsConverter]
type androidNotificationPriority =
  | Default
  | High
  | Low
  | Max
  | Min;

[@deriving jsConverter]
type androidNotificationVisibility =
  | Unknown
  | Public
  | Private
  | Secret;

[@deriving jsConverter]
type iosAlertStyle =
  | None
  | Banner
  | Alert;

[@deriving jsConverter]
type iosAllowsPreviews =
  | Never
  | Always
  | WhenAuthenticated;

[@deriving jsConverter]
type iosAuthorizationStatus =
  | NotDetermined
  | Denied
  | Authorized
  | Provisional
  | Ephemeral;

[@deriving jsConverter]
type permissionStatus =
  | Denied
  | Granted
  | Undetermined;

// Types
// this one is an interface but types depend on it and it's more of a type anyways
[@deriving jsProperties]
type nativeDevicePushToken = {
  data: string,
  [@mel.as "type"]
  type_: [ | `ios | `android],
};

type audioFlags = {
  enforceAudibility: bool,
  requestHardwareAudioVideoSynchronization: bool,
};

[@deriving jsProperties]
type audioAttributesInput = {
  [@mel.optional]
  contentType: option(androidAudioContentType),
  [@mel.optional]
  flags: option(audioFlags),
  [@mel.optional]
  usage: option(androidAudioUsage),
};

type beaconIdentityConstraint = {
  major: option(int),
  minor: option(int),
  uuid: string,
};

[@deriving jsProperties]
type calendarTriggerInput = {
  [@mel.optional]
  channelId: option(string),
  [@mel.optional]
  repeats: option(bool),
  [@mel.optional]
  day: option(int),
  [@mel.optional]
  hour: option(int),
  [@mel.optional]
  minute: option(int),
  [@mel.optional]
  month: option(int),
  [@mel.optional]
  second: option(int),
  [@mel.optional]
  timezone: option(string),
  [@mel.optional]
  weekOfMonth: option(int),
  [@mel.optional]
  weekOfYear: option(int),
  [@mel.optional]
  weekday: option(int),
  [@mel.optional]
  weekdayOrdinal: option(int),
  [@mel.optional]
  year: option(int),
};

[@deriving jsProperties]
type calendarTriggerInputValue = {
  [@mel.optional]
  day: option(int),
  [@mel.optional]
  hour: option(int),
  [@mel.optional]
  minute: option(int),
  [@mel.optional]
  month: option(int),
  [@mel.optional]
  second: option(int),
  [@mel.optional]
  timezone: option(string),
  [@mel.optional]
  weekOfMonth: option(int),
  [@mel.optional]
  weekOfYear: option(int),
  [@mel.optional]
  weekday: option(int),
  [@mel.optional]
  weekdayOrdinal: option(int),
  [@mel.optional]
  year: option(int),
};

[@deriving jsProperties]
type channelAwareTriggerInput = {channelId: string};

[@deriving jsProperties]
type dateTriggerInput = {
  channelId: option(string),
  date: Js.Date.t,
};

// This is described more complicated in docs but I think we can get away with this
type devicePushToken = nativeDevicePushToken;

type explicitlySupportedDevicePushToken = nativeDevicePushToken;

[@deriving jsProperties]
type notificationContent('a) = {
  [@mel.optional]
  body: option(string),
  [@mel.optional]
  data: option(Js.Dict.t('a)),
  [@mel.optional]
  sound: option([ | `default | `defaultCritical | `custom]),
  [@mel.optional]
  subtitle: option(string),
  [@mel.optional]
  title: option(string),
};

[@deriving jsProperties]
//TODO
type notificationTrigger;

type pushTokenListener = devicePushToken => unit;

// Interface types
type dateComponents = {
  calendar: string,
  day: int,
  era: int,
  hour: int,
  isLeapMonth: bool,
  minute: int,
  month: int,
  nanosecond: int,
  quarter: int,
  second: int,
  timeZone: string,
  weekOfMonth: int,
  weekOfYear: int,
  weekday: int,
  weekdayOrdinal: int,
  year: int,
  yearForWeekOfYear: int,
};
type geoCenter = {
  latitude: float,
  longitude: float,
};

// Interfaces
type audioAttributes = {
  contentType: androidAudioContentType,
  flags: audioFlags,
  usage: androidAudioUsage,
};

type beaconRegion = {
  beaconIdentityConstraint: option(beaconIdentityConstraint),
  major: option(int),
  minor: option(int),
  notifyEntryStateOnDisplay: bool,
  [@mel.as "type"]
  type_: [ | `beacon],
  uuid: option(string),
};

type calendarNotificationTrigger = {
  dateComponents,
  repeats: bool,
  [@mel.as "type"]
  type_: [ | `calendar],
};

type circularRegion = {
  center: geoCenter,
  radius: float,
  [@mel.as "type"]
  type_: [ | `circular],
};

type dailyNotificationTrigger = {
  hour: int,
  minute: int,
  [@mel.as "type"]
  type_: [ | `daily],
};

[@deriving jsProperties]
type dailyTriggerInput = {
  channelId: option(string),
  hour: int,
  minute: int,
  repeats: bool,
};

type expoPushToken = {
  data: string,
  [@mel.as "type"]
  type_: [ | `expo],
};

type expoPushTokenOptions = {
  applicationId: option(string),
  baseUrl: option(string),
  development: option(bool),
  deviceId: option(string),
  devicePushToken: option(devicePushToken),
  projectId: option(string),
  [@mel.as "type"]
  type_: option(string),
  url: option(string),
};

type firebaseRemoteMessageNotification = {
  body: option(string),
  bodyLocalizationArgs: option(array(string)),
  bodyLocalizationKey: option(string),
  channelId: option(string),
  clickAction: option(string),
  color: option(string),
  eventTime: option(float),
  icon: option(string),
  imageUrl: option(string),
  lightSettings: option(array(int)),
  link: option(string),
  localOnly: bool,
  notificationCount: option(int),
  notificationPriority: option(int),
  sound: option(string),
  sticky: bool,
  tag: option(string),
  ticker: option(string),
  title: option(string),
  titleLocalizationArgs: option(array(string)),
  titleLocalizationKey: option(string),
  usesDefaultLightSettings: bool,
  usesDefaultSound: bool,
  usesDefaultVibrateSettings: bool,
  vibrateTimings: option(array(int)),
  visibility: option(int),
};

type firebaseRemoteMessage = {
  collapseKey: option(string),
  data: Js.Dict.t(string),
  from: option(string),
  messageId: option(string),
  messageType: option(string),
  notification: option(firebaseRemoteMessageNotification),
  originalPriority: int,
  priority: int,
  sentTime: float,
  [@mel.as "to"]
  to_: option(string),
  ttl: int,
};

type iosNotificationPermissionsRequest = {
  allowAlert: option(bool),
  allowAnnouncements: option(bool),
  allowBadge: option(bool),
  allowCriticalAlerts: option(bool),
  allowDisplayInCarPlay: option(bool),
  allowProvisional: option(bool),
  allowSound: option(bool),
  provideAppNotificationSettings: option(bool),
};

type locationNotificationTrigger = {
  region: [ | `CircularRegion(circularRegion) | `BeaconRegion(beaconRegion)],
  repeats: bool,
  [@mel.as "type"]
  type_: [ | `location],
};

type notificationRequest('a) = {
  content: notificationContent('a),
  identifier: string,
  trigger: notificationTrigger,
};
type notification('a) = {
  date: float,
  request: notificationRequest('a) // TODO
};

type notificationActionOptions = {
  isAuthenticationRequired: bool,
  isDestructive: bool,
  opensAppToForeground: bool,
};

type notificationActionTextInput = {
  placeholder: string,
  submitButtonTitle: string,
};

type notificationAction = {
  buttonTitle: string,
  identifier: string,
  options: option(notificationActionOptions),
  textInput: option(notificationActionTextInput),
};

type notificationBehavior = {
  priority: option(androidNotificationPriority),
  shouldPlaySound: bool,
  shouldSetBadge: bool,
  shouldShowAlert: bool,
};

type notificationChannel = {
  audioAttributes,
  bypassDnd: bool,
  description: option(string),
  enableLights: bool,
  enableVibrate: bool,
  groupId: option(string),
  id: string,
  importance: androidImportance,
  lightColor: string,
  lockscreenVisibility: androidNotificationVisibility,
  name: option(string),
  showBadge: bool,
  sound: option([ | `Default | `Custom]),
  vibrationPattern: option(array(float)),
};

type notificationChannelGroup = {
  channels: array(notificationChannel),
  description: option(string),
  id: string,
  isBlocked: option(bool),
  name: option(string),
};

[@deriving jsProperties]
type notificationChannelGroupInput = {
  [@mel.optional]
  description: option(string),
  [@mel.optional]
  name: option(string),
};
// TODO: This extends ProxyNativeModule but I didn't write in what it inherits
[@deriving jsProperties]
type notificationChannelGroupManager = {
  [@mel.optional]
  deleteNotificationChannelGroupAsync: option(string => Js.Promise.t(unit)),
  [@mel.optional]
  getNotificationChannelGroupAsync:
    option(string => Js.Promise.t(option(notificationChannelGroup))),
  [@mel.optional]
  getNotificationChannelGroupsAsync:
    option(unit => Js.Promise.t(array(notificationChannelGroup))),
  [@mel.optional]
  setNotificationChannelGroupAsync:
    option(notificationChannelGroupInput => Js.Promise.t(unit)),
};

// Functions / Methods
// Fetch tokens for push notifications
[@mel.module "expo-notifications"]
external addPushTokenListener:
  pushTokenListener => ReactNative.EventSubscription.t =
  "addPushTokenListener";

[@mel.module "expo-notifications"]
external getDevicePushTokenAsync: unit => Js.Promise.t(devicePushToken) =
  "addNotificationResponseReceivedListener";

[@mel.module "expo-notifications"]
external getExpoPushTokenAsync: expoPushTokenOptions => expoPushToken =
  "getExpoPushTokenAsync";

[@mel.module "expo-notifications"]
external removePushTokenSubscription: ReactNative.EventSubscription.t => unit =
  "removePushTokenSubscription";

// Listen to notification events
[@mel.module "expo-notifications"]
external addNotificationReceivedListener: unit => unit =
  "addNotificationReceivedListener";

[@mel.module "expo-notifications"]
external addNotificationResponseReceivedListener: unit => unit =
  "addNotificationResponseReceivedListener";

[@mel.module "expo-notifications"]
external addNotificationsDroppedListener: unit => unit =
  "addNotificationsDroppedListener";

[@mel.module "expo-notifications"]
external getLastNotificationResponseAsync: unit => unit =
  "getLastNotificationResponseAsync";

[@mel.module "expo-notifications"]
external removeNotificationSubscription: unit => unit =
  "removeNotificationSubscription";

[@mel.module "expo-notifications"]
external useLastNotificationResponse: unit => unit =
  "useLastNotificationResponse";

// Handle incoming notifications when app is in foreground
[@mel.module "expo-notifications"]
external setNotificationHandler: unit => unit = "setNotificationHandler";

[@mel.module "expo-notifications"]
external registerTaskAsync: unit => unit = "registerTaskAsync";

[@mel.module "expo-notifications"]
external unregisterTaskAsync: unit => unit = "unregisterTaskAsync";

[@mel.module "expo-notifications"]
external getPermissionsAsync: unit => unit = "getPermissionsAsync";

[@mel.module "expo-notifications"]
external requestPermissionsAsync: unit => unit = "requestPermissionsAsync";

[@mel.module "expo-notifications"]
external getBadgeCountAsync: unit => unit = "getBadgeCountAsync";

[@mel.module "expo-notifications"]
external setBadgeCountAsync: unit => unit = "setBadgeCountAsync";

[@mel.module "expo-notifications"]
external cancelAllScheduledNotificationsAsync: unit => unit =
  "cancelAllScheduledNotificationsAsync";

[@mel.module "expo-notifications"]
external cancelScheduledNotificationAsync: unit => unit =
  "cancelScheduledNotificationAsync";

[@mel.module "expo-notifications"]
external getAllScheduledNotificationsAsync: unit => unit =
  "getAllScheduledNotificationsAsync";

[@mel.module "expo-notifications"]
external getNextTriggerDateAsync: unit => unit = "getNextTriggerDateAsync";

[@mel.module "expo-notifications"]
external presentNotificationAsync: unit => unit = "presentNotificationAsync";

[@mel.module "expo-notifications"]
external scheduleNotificationAsync: unit => unit = "scheduleNotificationAsync";

[@mel.module "expo-notifications"]
external dismissAllNotificationsAsync: unit => unit =
  "dismissAllNotificationsAsync";

[@mel.module "expo-notifications"]
external dismissNotificationAsync: unit => unit = "dismissNotificationAsync";

[@mel.module "expo-notifications"]
external getPresentedNotificationsAsync: unit => unit =
  "getPresentedNotificationsAsync";

[@mel.module "expo-notifications"]
external setAutoServerRegistrationEnabledAsync: unit => unit =
  "setAutoServerRegistrationEnabledAsync";

[@mel.module "expo-notifications"]
external unregisterForNotificationsAsync: unit => unit =
  "unregisterForNotificationsAsync";
