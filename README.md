# Garminuino
There has two sub-project use GarminHUD as:
1. an app, Google Map HUD  (Android App+GarminHUD).  
 * [Downloading newest release App here.](https://github.com/skyforcetw/Garminuino/releases)
 * [Further Information for Android App.](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMaps_HUD/README.md)  
   * [Install.](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMaps_HUD/INSTALL.md)  
   * [First Use.](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMaps_HUD/FIRST_USE.md)  
   * [Instruction.](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMaps_HUD/INSTRUCTIONv052.md)  
 * [Android Auto Cooperation.](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMaps_HUD/AndroidAuto.md)
2. a speedometer HUD  (Arduino+GarminHUD, STOP MAINTAIN)
 

Belows are two sub-proejct put together: GoogleMap navigation HUD(Left)+ Speedometer HUD(Center)
<img src="./pics/124220.jpg" alt="Two Garmin HUD application" width="500"/>

Belows are two sub-proejct & Android Auto put together: <br>
GoogleMap navigation HUD(Left1)+ Speedometer HUD(Left2) + Android auto(Right1)<br>
<img src="./pics/163633.jpg" alt="Two Garmin HUD application + Android Auto" width="500"/>

Android App: Google Map HUD

<img src="./pics/451627.jpg" alt="App layout" width="400"/>

## GoogleMap navigation HUD App Release History ##

### [2020-09-29 v0.8.2](https://github.com/skyforcetw/Garminuino/releases/download/0.8.2/gmaps_hud-release_v0.8.2.apk)
Fix arrivals arrow.

### [2020-09-26 v0.8.1](https://github.com/skyforcetw/Garminuino/releases/download/v0.8.1/gmaps_hud-release_v0.8.1.apk)
Add support for BMW HUD , thanks for intervigilium's contribution.

### [2020-07-04 v0.7.0](https://github.com/skyforcetw/Garminuino/releases/download/0.7.0/gmaps_hud-release_v0.7.0.apk)
Fix some bug for BT auto-connection.

### [2020-03-02 v0.6.4](https://github.com/skyforcetw/Garminuino/releases/download/0.6.4/gmaps_hud-release_v0.6.4.apk)
Fix time parsing error when XX:00.

### [2020-01-20 v0.6.1](https://github.com/skyforcetw/Garminuino/releases/download/0.6.1/gmaps_hud-release_v0.6.1.apk)
Use more robust arrow recognize + Fix lane detect no function bug.

### [2019-11-11 v0.5.4](https://github.com/skyforcetw/Garminuino/releases/download/0.5.4/gmaps_hud-release_v0.5.4.apk)
Fix some bugs for traffic detection

### [2019-10-23 v0.5.2](https://github.com/skyforcetw/Garminuino/releases/download/0.5.2/gmaps_hud-release_v0.5.2.apk)
Support Arrow Style v2 / Traffic alert speed is adjustable

Arrow v1 style/Arrow v2 style:

![v1](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMap_Arrow_Recognize/PatternRecognize/workdir/Google_Arrow2/Right.png)![v2](https://github.com/skyforcetw/Garminuino/blob/master/GoogleMap_Arrow_Recognize/PatternRecognize/workdir/Google_Arrow3%20-%20remove%20alpha/Right.png)

[New instruction for v0.5.2.](./GoogleMaps_HUD/INSTRUCTIONv052.md)

### [2019-09-26 v0.4.9](https://github.com/skyforcetw/Garminuino/releases/download/0.4.9/gmaps_hud-release_v0.4.9.apk)
Polish Support & New Dark Mode.

### [2019-08-23 v0.4.7](https://github.com/skyforcetw/Garminuino/releases/download/0.4.7/gmaps_hud-release_v0.4.7.apk)
Simple controls in Notification.

**NOTE** If your android is below Android 8.0(Oreo), please download [this one](https://github.com/skyforcetw/Garminuino/releases/download/0.4.7/gmaps_hud-release_v0.4.7.android6.0.apk).


### [2019-08-11 v0.4.6](https://github.com/skyforcetw/Garminuino/releases/download/0.4.6/gmaps_hud-release_v0.4.6.apk)
Lane detection mechanism revision.

### 2019-08-11 v0.4.4
Lane detection mechanism.(had some bug, need fix)

### [2019-08-06 v0.4.3](https://github.com/skyforcetw/Garminuino/releases/download/0.4.3/gmaps_hud-release_v0.4.3.apk)
1. Add traffic detect function
2. Add reset bt function, test it when your bt connection is unable.

### [2019-03-15 v0.4.0s](https://github.com/skyforcetw/Garminuino/releases/download/0.4.0s/gmaps_hud-release.apk)
Auto/Manual Brightness Setting for Garmin HUD.

### 2019-02-19 v0.3.1
Add arrow recognize for roundabout.  
According to country, arrows of roundabout  can classification to clockwise or counter-clockwise.  
Left-sided drive / Right-hand traffic  country, like USA, roundabout arrows are counter-clockwise.  
Right-sided drive/ Left-hand traffic  country, like United Kingdom, roundabout arrows are clockwise.  

### 2019-02-11 v0.2.0
New layout of app.
Add some status indicator for qucik debug.

### 2019-02-06
It's necessary to figure out auto coneection is working well or not, so I removed the naevtamarkus' BT Library first.
I also re-arrange some layout of app, for convient to use.

### 2019-01-15 v0.1.6
Thanks for Niklas04's help, Fix speedmeter, autoconnect.

### 2019-01-07
Thanks for Niklas04's help to improve parsing & add German language support.

### 2018-11-05
Auto connect to last binded bluetooth device(not tested yet).

### 2018-10-30
Add english/korean language support, thanks for cloddin's help.
We have pre-release now, please download and try it from https://github.com/skyforcetw/Garminuino/releases

### 2018-10-01
All GoogleMaps_HUD app source code is uploaded!

### 2018-09-07 _VERY IMPORTANT UPDATE!_
A [Vega-HUD](https://visualgoal.com.tw/%E9%A6%96%E9%A0%81/) feature enlightened me a directed way to get turn-by-turn infomation.
I can get turn-by-turn from google map's notification(android)!
It's a big change for Garminuino, because it's mean I don't need arduino anymore!
So navigation part of Garminuino turn into a pure android's app(apk) now!

## [GoogleMaps HUD App](https://github.com/skyforcetw/Garminuino/tree/master/GoogleMaps_HUD)
A pure android app, for project navi-info of google map navigation.
Works just like garmin streetpilot with Garmin HUD.

***

## ToDo List
1. ~~Add auto-connection function.~~
2. Auto lanunch google map when HUD connected.
3. ~~Comment source-code.
4. ~~Show some usage infomation when navigation is done, don't make it seems hang when navigating done.~~
5. ~~Figure out auto connection is working well or not.~~
6. ~~Lets "Show Speed" function working well.~~
7. ~~Better auto-connection with GarminHUD
8. ~~Support Sygic & OsmAnd (GIVE UP! Cause of bad text recongnition).
9. Support Android Q's screen capture.
10. Improve arrow recognition.

***

## Authors

* **skyforce Shen** - *Initial work* - [github](https://github.com/skyforcetw) skyforce@gmail.com

## Contributor
* **Gabriel Valky** / **Frank Huebenthal** - *garmin hud protocol research* - [github](https://github.com/gabonator/Work-in-progress/tree/master/GarminHud) 

* **Niklas04** - help improve parsing & add German language support
[github](https://github.com/Niklas04) 

* **intervigilium** - add support for BMW HUD 
[github](https://github.com/intervigilium) 

* **Android-BluetoothSPPLibrary** - Bluetooth SPP Library, use to link Garmin HUD.
[github](https://github.com/akexorcist/Android-BluetoothSPPLibrary) 

* ~~**Android-BluetoothSPPLibrary** - Bluetooth SPP Library also, which fixed issue of auto connection.
[github](https://github.com/naevtamarkus/Android-BluetoothSPPLibrary)~~

***

Hence the information below is not necessary anymore, but I still keep it for commemorative.

![Initial concept of Garminuino](https://trello-attachments.s3.amazonaws.com/5604cb6e078e570dfc9c7404/1794x1080/accfe9e4f1f1d10e8bb62d7630130425/sketch-1443154690685.jpg "Initial concept of Garminuino")
This is the inital concept of Garminuino, but the implment is slight difference to the concept. For example, Garmin Hud is not linked by BLE, so BLE moduble is needless.

## [Speedometer HUD](https://github.com/skyforcetw/Garminuino/tree/master/speedometer%20HUD)

[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/P0d8nm3kuxs/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLAh96qD5deX_DeYAHk9CHNptn97JQ)](https://www.youtube.com/watch?v=P0d8nm3kuxsE)

(click image can link to Youtube film)

A OBD/CanBus parser by Arduino, and a speed info transmitter by bluetooth(to GarminHUD) .

## [navigation HUD](https://github.com/skyforcetw/Garminuino/tree/master/navigation%20HUD)      (deprecated now!)

[![IMAGE ALT TEXT HERE](https://i.ytimg.com/vi/VWV_F9V6yoA/hqdefault.jpg?sqp=-oaymwEZCPYBEIoBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLDerjxVyOMK8V3hm9DaY-8zb3a1DQ)](https://www.youtube.com/watch?v=VWV_F9V6yoA)

(click image can link to Youtube film)

Besides parts of Speedometer HUD, a USB Host Shield with a Android mobile phone can fetch Google Navigation info, and transmit info by bluetooth to GarminHUD, too.

***

