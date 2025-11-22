# 🛰️ RadarRobot – Autonomous Scanning Car with Ultrasonic Radar & App Integration
### Arduino + Processing + Mechatronic System

RadarRobot is an integrated robotics system combining Arduino-based control, ultrasonic radar scanning, Processing real-time visualization, and a future Java/Android app interface.
The vehicle performs continuous sweeping of its surroundings using a servo-mounted HC-SR04 distance sensor while sending angle–distance data for live visualization.

The final objective is a fully controllable robotic car with Bluetooth communication (HC-05) and a migrated radar interface inside a mobile app.

🔧 Project Structure

---/Arduino
  ---  ├── Radarrapido.ino
  ---  ├── controlcarro.ino    # Main radar scanning + HC-SR04 + servo logic
   --- └── MotorControl.ino     # (optional) Motor driver tests it's not uploadaed (yet)

   ---
   
/Processing
    --- ├── radar_visualizer.pde # Complete radar UI (angle, distance, sweep, arcs)
   --- ├── data/
    --- └── utils.pde            # (optional) Additional visual modules
    
---

/App
    --- ├── ui_mockups/
    --- ├── bluetooth_tests/
   --- └── RadarAppBlueprint.txt

🚗 System Overview
Hardware Platform

Arduino UNO / Mega

HC-SR04 ultrasonic sensor

SG90 / MG995 servo

L293d / L298N motor shield driver or dual-bridge module

HC-05 Bluetooth module

4 × 1.5V AA high-drain batteries (with driver)

Optional 9V battery for logic (NOT for motors)

Core Functions

✔ 180° radar sweep with servo
✔ Real-time distance measurement
✔ Serial data streaming in angle,distance. format
✔ Processing UI with dynamic sweeping line
✔ Object detection under 40 cm
✔ Data smoothing & motion-blur simulation
✔ Future app integration (Java/AndroidStudio)

📡 How It Works
1. Arduino

The microcontroller performs:

Servo sweeping (0° → 180° → 0°)

Ultrasonic measurement at sweep limits

Serial transmission to Processing:

0,25.
1,24.
2,24.
...
180,12.

2. Processing Visualization
Processing receives the data, parses angle & distance, and renders the radar:
Concentric range arcs (10/20/30/40 cm)
Rotating green sweep line
Red markers for detectable objects
Fade effect for persistent radar trails
This creates a full military-style radar interface.

3. App (Work in Progress)
The radar UI and motor controls will be migrated into a native Android app with:
HC-05 Bluetooth connection
Live radar rendering
On-screen driving joystick
Auto/Manual scanning modes

🛠️ Setup Instructions
Arduino

Open the .ino file from /Arduino/

Select the correct board & port

Upload to the microcontroller

Make sure the HC-SR04 and servo are wired correctly:

trig → pin 10

echo → pin 11

Servo → pin 9/10 depending on sketch

Processing

Install Processing 3.x or 4.x

Open the .pde file in /Processing/

Set the correct COM port:

myPort = new Serial(this, "COM3", 9600);


Run the sketch

You should immediately see the radar sweep

🔮 Roadmap (Next Steps)
Feature	Status
Arduino radar + motor control	✔ Complete
Processing radar UI	✔ Complete
Bluetooth control (HC-05)	✔ Tested
App UI prototype	⏳ In progress
Full app migration (Java)	⏳ Planned
Real-time app radar	⏳ Pending
Auto-navigation mode	⏳ Future

📘 Credits
Base radar visual logic inspired by open-source Processing radar projects by the community.
All modifications, optimizations, UI upgrades, and system integration by Choisaint.

🧪 License
MIT License – free to use, modify, and distribute.

⭐ Support

If this project helped you, consider giving the repository a star on GitHub.
