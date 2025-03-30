# Ride Sharing System – Smalltalk (Pharo)

This project is a Smalltalk-based Ride Sharing System that demonstrates core Object-Oriented Programming (OOP) principles including:

- **Encapsulation**
- **Inheritance**
- **Polymorphism**

It is implemented in **Pharo Smalltalk**, and can be run using the Pharo environment and Transcript output.

---

## Contents

- `RideSharingSystem.st` – The source file containing all class definitions and methods for:
  - `Ride`, `StandardRide`, `PremiumRide`
  - `Driver`
  - `Rider`

---

## How to Load & Run

### Step 1: Download Pharo

- Download from: [https://pharo.org/download](https://pharo.org/download)
- Install the **Pharo Launcher** and create a new image (e.g., Pharo 12 Stable)

---

### Step 2: Load the Code

1. Launch your Pharo image
2. Go to **`File > File in...`**
3. Select `RideSharingSystem.st` from your local system
4. The classes will now be available in the System Browser under the package `RideSharingSystem`

---

### Step 3: Run Demo Code

1. Open a **Playground** (`Ctrl/Cmd+O+W`)
2. Paste the following demo script:

```smalltalk
"Demo: Creating objects and demonstrating OOP behavior"

| ride1 ride2 driver rider rides |

ride1 := StandardRide new.
ride1 initializeWith: 'R001' pickup: 'Downtown' dropoff: 'Airport' distance: 15.

ride2 := PremiumRide new.
ride2 initializeWith: 'R002' pickup: 'Mall' dropoff: 'Hotel' distance: 10.

"Demonstrate polymorphism"
rides := { ride1. ride2 }.
rides do: [:r | 
    Transcript show: r rideDetails; 
    show: ' | Fare: $', r fare asString; cr].

"Create and use Driver"
driver := Driver new.
driver initializeWith: 'D100' name: 'Alice' rating: 4.9.
driver addRide: ride1.
driver addRide: ride2.
Transcript show: driver getDriverInfo; cr.

"Create and use Rider"
rider := Rider new.
rider initializeWith: 'U001' name: 'Bob'.
rider requestRide: ride1.
rider requestRide: ride2.
rider viewRides do: [:rd | Transcript show: rd; cr].
```
3. Press `Ctrl/Cmd+D` to run it  
4. Open **Transcript** (`Browse > Transcript`) to view the output

---

### 💡 Features

- **Ride**: Abstract base class for ride details  
- **StandardRide**: Ride type with flat fare per distance  
- **PremiumRide**: Ride type with higher fare rate  
- **Driver**: Stores completed rides  
- **Rider**: Stores requested rides  
- Demonstrates OOP concepts via polymorphism with ride collections

---

### 🧠 Object-Oriented Principles

- **Encapsulation**: Internal ride collections in `Driver` and `Rider` are private and accessed only through methods  
- **Inheritance**: `StandardRide` and `PremiumRide` inherit shared behavior from `Ride`  
- **Polymorphism**: The `fare` method is overridden in each subclass and called dynamically at runtime

---

### Requirements

- [Pharo](https://pharo.org/download) (version 11 or 12 recommended)  
- Works on Windows, macOS, and Linux

---
