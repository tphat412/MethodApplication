# Method Selection MFC Application

A C++ MFC application implementing a reusable method selection interface using the **Model–View–Controller (MVC)** design pattern with a **Publisher–Subscriber** notification system.

---

## Overview

This application allows users to choose different methods across categories such as **Ground Water** and **Thermal**. A single reusable dialog handles method selection for any category, and the selected method is reflected in the main window.

---

## Architecture

```
User Interaction
       │
       ▼
View (Dialogs)
       │
       ▼
Controller
       │
       ▼
Model (Method Configuration)
       │
       ▼
Publisher → Subscriber notification → View updates
```

### Model — `MethodModel`

Represents the state of a method configuration. Each model stores:

- The list of available method options
- The currently selected method

Options and label content are defined in **resource files**, so UI content can be updated without modifying source code.

### Controller — `MethodController`

Manages all `MethodModel` objects and acts as the sole communication bridge between the Model and View.

Responsibilities:
- Creating and managing models for each `MethodType`
- Loading method options from resource files
- Updating selected methods based on user input
- Providing model data access to views

### View — Dialogs

#### Method Application Dialog
- Displays the currently selected Groundwater and Thermal methods
- Contains buttons that open the reusable method selection dialog

#### Method Selection Dialog (`MethodSelectionDlg`)
A single reusable dialog parameterized by `MethodType`. It dynamically loads:
- Dialog title and label text from resource
- Get combo box options from models

This avoids duplicating dialogs per category and improves maintainability.

---

## Resource-Based Configuration

Method options and UI labels are stored in the Windows resource string table:

```
IDS_GROUND_METHODS   →  "Static Water; Steady FEA; Transient FEA"
IDS_THERMAL_METHODS  →  "Static Temperature; Steady Thermal FEA; Transient Thermal FEA"
```

### Default Behavior

When a model loads its options, the **first option is automatically selected** as the default. This ensures the main dialog always displays a valid method on startup.

---

## Data Flow

1. Main dialog opens the reusable `MethodSelectionDlg`
2. Dialog loads available options from the controller
3. User selects a method and presses **OK**
4. Controller updates the corresponding `MethodModel`
5. Model notifies its subscribers (Publisher–Subscriber pattern)
6. Main dialog updates its labels to reflect the new selection

---

## Extending the System

Adding a new method category requires minimal changes:

1. Add a new `MethodType` enum value
2. Add resource strings for method options and labels
3. Add a button in the main dialog

> No changes to `MethodSelectionDlg` or `MethodController` logic are required.
