<div align="center">
  <img src="assets/vu_exterieur.jpeg" alt="Régulateur Thermique Connecté" width="100%" style="border-radius: 12px; max-height: 480px; object-fit: cover;">
  <br/><br/>
  <h1>🌡️ RÉGULATEUR THERMIQUE CONNECTÉ</h1>
  <p>
    <strong>Système connecté de supervision de température et pilotage intelligent de la ventilation via Bluetooth</strong>
  </p>
  <p>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Microcontrôleur-Arduino_Uno-00979C.svg?style=flat-square&logo=arduino" alt="Platform"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Langage-C%2FC%2B%2B-00599C.svg?style=flat-square&logo=cplusplus" alt="Language"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Communication-Bluetooth_HC--05-0A84FF.svg?style=flat-square&logo=bluetooth" alt="Bluetooth"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Application-MIT_App_Inventor-E83524.svg?style=flat-square" alt="App Inventor"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Centre-Max__Adis_2026-D90429.svg?style=flat-square" alt="Max_Adis"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Statut-Termin%C3%A9_%26_Valid%C3%A9-success.svg?style=flat-square" alt="Status"></a>
  </p>
</div>

<br/>

## 📖 À propos du Projet

Le **Régulateur Thermique Connecté** est une solution domotique et IoT conçue pour maintenir des conditions climatiques idéales dans des environnements clos (habitations, baies de serveurs, laboratoires, serres agricoles). 

Il associe une unité de traitement centrale **Arduino Uno**, une sonde numérique de température **DHT11**, un module de communication sans fil **HC-05** et un circuit d'isolation de puissance par **relais 5V** pour piloter une ventilation active.

L'utilisateur bénéficie d'une visibilité en direct sur la température via son smartphone et peut configurer les seuils de bascule ou forcer la commande manuelle du ventilateur en temps réel.

---

## ✨ Fonctionnalités Clés

* 📊 **Supervision en temps réel** : Mesure continue de la température ambiante et transmission cadencée chaque seconde vers l'application mobile.
* 🤖 **Mode Automatique Intelligent (`M1`)** : Déclenchement automatique de la ventilation dès que la température mesurée franchit le seuil critique (seuil réglable, valeur initiale : 31.0°C).
* 🕹️ **Mode Manuel Prioritaire (`M0`)** : Pilotage forcé de l'actionneur (Marche `A` / Arrêt `B`) pour un rafraîchissement immédiat à la demande de l'utilisateur.
* 📡 **Liaison Sans Fil Indépendante** : Communication Bluetooth SPP directe sans dépendance à une connexion Internet ou à un routeur Wi-Fi.
* 🔒 **Sécurité Électrique** : Isolation galvanique de la charge de puissance par relais optocouplé protégeant le microcontrôleur.

---

## 🛠️ Nomenclature Matérielle (BOM)

| Matériel | Rôle & Utilité dans le Système | Spécification |
| :--- | :--- | :--- |
| **Arduino Uno** | Traite les données capteur, exécute les consignes et commande le relais | ATmega328P, 16 MHz |
| **Capteur DHT11** | Mesure précise de la température ambiante (et humidité) | Signal numérique 1-wire |
| **Module HC-05** | Assure la communication série sans fil bidirectionnelle avec le smartphone | Bluetooth v2.0+EDR (UART) |
| **Module Relais 1 Canal** | Isole et commute l'alimentation du moteur du ventilateur | 5V DC, contact sec NO/NC |
| **Ventilateur (Moteur CC + Hélice)** | Crée le flux d'air pour évacuer la chaleur excessive | 5V / 12V DC |
| **Plaque d'essai (Breadboard)** | Montage et prototypage rapide sans soudure | Standard 830 points |
| **Fils de connexion (Jumpers)** | Liaisons électriques mâle-mâle et mâle-femelle | Multi-couleurs |
| **Alimentation & Câble USB** | Alimente le microcontrôleur et fournit la tension requise | USB 5V / Source externe |
| **Smartphone Android** | Affiche les données et sert d'interface tactile de supervision | Compatible Bluetooth |

---

## 🔌 Schéma de Câblage & Pinout

| Composant | Broche Composant | Broche Arduino Uno | Remarques |
| :--- | :--- | :--- | :--- |
| **DHT11** | DATA | `Pin 2` | Signal de température |
| **DHT11** | VCC / GND | `5V` / `GND` | Alimentation capteur |
| **HC-05** | TXD | `Pin 10` (RX Arduino) | Réception série logicielle |
| **HC-05** | RXD | `Pin 11` (TX Arduino) | Transmission série logicielle |
| **HC-05** | VCC / GND | `5V` / `GND` | Alimentation Bluetooth |
| **Relais 1 canal** | IN | `Pin 3` | Signal de commande (Actif LOW) |
| **Relais 1 canal** | VCC / GND | `5V` / `GND` | Alimentation bobine |
| **Ventilateur** | Borne (+) | Sortie NO Relais | Coupure commandée |

---

## 💻 Microprogramme & Logique Embarquée

Le microprogramme C++ [`CODE_FINAL.ino`](CODE_FINAL.ino) est cadencé avec `millis()` (gestion temporelle non bloquante) garantissant une réactivité immédiate aux commandes Bluetooth entrantes sans délai parasite (`delay()`).

```cpp
// Extrait du traitement des commandes Bluetooth
if (mySerial.available()) {
  String commande = mySerial.readStringUntil('\n');
  commande.trim();

  if (commande == "M1") {
    modeAuto = true;   // Bascule en régulation automatique
  }
  else if (commande == "M0") {
    modeAuto = false;  // Bascule en pilotage manuel
  }
  else if (commande.startsWith("S")) {
    seuil = commande.substring(1).toFloat();  // Ex: "S28.5" -> Seuil fixé à 28.5°C
  }
  else if (commande == "A" && !modeAuto) {
    digitalWrite(pinRelais, LOW);  // Ventilateur ON
  }
  else if (commande == "B" && !modeAuto) {
    digitalWrite(pinRelais, HIGH); // Ventilateur OFF
  }
}
```

---

## 📱 Application Mobile (ThermoControl BT)

Développée avec **MIT App Inventor**, l'application permet :
1. La recherche et la connexion Bluetooth au module **HC-05**.
2. L'affichage en temps réel de la température ambiante mesurée.
3. Un potentiomètre / curseur tactile pour modifier dynamiquement le seuil critique.
4. Les boutons de commande manuelle : **Marche (ON)** et **Arrêt (OFF)**.
5. Une sécurité intégrée empêchant les commandes manuelles erronées lorsque le mode automatique est actif.

---

## 📸 Galerie de la Maquette

<div align="center">
  <table border="0">
    <tr>
      <td align="center">
        <img src="assets/vu_exterieur.jpeg" width="400px" style="border-radius: 8px;" alt="Vue extérieure"/>
        <br/>
        <strong>Vue extérieure de la maquette</strong>
      </td>
      <td align="center">
        <img src="assets/interieur.jpeg" width="400px" style="border-radius: 8px;" alt="Vue intérieure"/>
        <br/>
        <strong>Vue intérieure & intégration technique</strong>
      </td>
    </tr>
  </table>
</div>

---

## 👥 Équipe de Réalisation & Crédits

Ce projet a été réalisé dans le cadre de la session pratique de formation dispensée par le **Centre de Formation Max_Adis** (Édition 2026 — Vague 1) :

* **Groupe n°5 — Smart Innovators** :
  * 👤 **FADONOUGBO Anselme**
  * 👤 **HOUNKOKOE Trifène**
  * 👤 **KINDOMISSI Achille**

* **Supervision & Écosystème** : 
  * 🏫 **Centre de formation Max_Adis** — *« Crée et contrôle tes propres systèmes intelligents »*
  * 📍 Porto-Novo, Bénin
  * 🌐 Site officiel : [maxadis.vercel.app](https://maxadis.vercel.app)

---

## 📄 Licence

Projet open-source réalisé à des fins pédagogiques et utilitaires. Distribué sous licence MIT.
