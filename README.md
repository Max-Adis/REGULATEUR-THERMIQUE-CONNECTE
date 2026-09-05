<div align="center">
  <img src="assets/logo.jpg" alt="Logo ThermoControl BT" width="160px" style="border-radius: 20px; box-shadow: 0 8px 20px rgba(0, 114, 206, 0.2);">
  <br/><br/>
  <h1>THERMOCONTROL BT</h1>
  <h3>Système Intelligent de Régulation Thermique et de Ventilation Connectée</h3>
  <p>
    <strong>Surveillance continue de la température ambiante et pilotage automatique de la ventilation par liaison Bluetooth</strong>
  </p>
  <p>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Plateforme-Arduino_Uno-0072CE.svg?style=flat-square" alt="Platform"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Sonde-DHT11_Numérique-F97316.svg?style=flat-square" alt="Sensor"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Liaison-Bluetooth_HC--05-38BDF8.svg?style=flat-square" alt="Bluetooth"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Application-MIT_App_Inventor-E83524.svg?style=flat-square" alt="App Inventor"></a>
    <a href="https://github.com/Max-Adis/REGULATEUR-THERMIQUE-CONNECTE"><img src="https://img.shields.io/badge/Statut-Validé-success.svg?style=flat-square" alt="Status"></a>
  </p>
</div>

<br/>

## Présentation & Utilité du Projet

**ThermoControl BT** est une solution domotique conçue pour protéger les locaux et les équipements sensibles contre les risques critiques de surchauffe (baies de serveurs, locaux techniques, serres agricoles, habitations).

Le système assure une triple mission :
1. **Surveillance continue** : Mesure en direct de la température ambiante et transmission instantanée vers une application smartphone.
2. **Refroidissement autonome** : Déclenchement automatique de la ventilation dès que la température franchit un seuil limite paramétrable.
3. **Contrôle sans fil direct** : Possibilité pour l'utilisateur de forcer la mise en marche ou l'arrêt de la ventilation à distance sans déplacement.

---

## Fonctionnalités Majeures

* **Protection active 24h/24** : Prévention des pannes électroniques et maintien d'un climat sain.
* **Double mode de fonctionnement** :
  * **Mode Automatique (`M1`)** : Déclenchement autonome basé sur la comparaison avec la température de consigne.
  * **Mode Manuel (`M0`)** : Forçage des états Marche (`A`) et Arrêt (`B`) depuis l'application mobile.
* **Autonomie réseau** : Liaison Bluetooth SPP directe ne nécessitant aucun abonnement Internet ni box Wi-Fi.
* **Sécurité électrique renforcée** : Isolation galvanique par relais optocouplé protégeant le microcontrôleur contre les surtensions inductives du moteur.

---

## Nomenclature Matérielle (BOM)

| Matériel | Rôle & Utilité dans le Système | Spécification |
| :--- | :--- | :--- |
| **Arduino Uno** | Unité centrale de calcul et d'orchestration | ATmega328P, 16 MHz |
| **Capteur DHT11** | Mesure de la température ambiante | Signal numérique 1-fil |
| **Module HC-05** | Passerelle sans fil série vers l'application | UART SPP 9600 bauds |
| **Module Relais 1 Canal** | Commutation sécurisée de la puissance | 5V DC, contact sec NO/NC |
| **Ventilateur (Moteur CC + Hélice)** | Évacuation forcée des calories excédentaires | 5V / 12V DC |
| **Plaque d'essai (Breadboard)** | Prototypage rapide sans soudure | Standard 830 points |
| **Fils Jumpers** | Câblage électrique du prototype | Mâle-Mâle / Mâle-Femelle |

---

## Schéma de Câblage & Pinout

| Composant | Broche Composant | Broche Arduino Uno | Description |
| :--- | :--- | :--- | :--- |
| **DHT11** | DATA | `Pin 2` | Signal de température |
| **DHT11** | VCC / GND | `5V` / `GND` | Alimentation capteur |
| **HC-05** | TXD | `Pin 10` (RX) | Réception série logicielle |
| **HC-05** | RXD | `Pin 11` (TX) | Transmission série logicielle |
| **HC-05** | VCC / GND | `5V` / `GND` | Alimentation Bluetooth |
| **Relais 1 Canal** | IN | `Pin 3` | Commande de déclenchement (Actif LOW) |
| **Relais 1 Canal** | VCC / GND | `5V` / `GND` | Alimentation bobine |

---

## Galerie du Projet

<div align="center">
  <table border="0">
    <tr>
      <td align="center">
        <img src="assets/vu_exterieur.jpeg" width="420px" style="border-radius: 12px; box-shadow: 0 4px 15px rgba(0,0,0,0.1);" alt="Vue extérieure"/>
        <br/><br/>
        <strong>Vue extérieure de la maquette</strong>
      </td>
      <td align="center">
        <img src="assets/interieur.jpeg" width="420px" style="border-radius: 12px; box-shadow: 0 4px 15px rgba(0,0,0,0.1);" alt="Vue intérieure"/>
        <br/><br/>
        <strong>Vue intérieure & intégration technique</strong>
      </td>
    </tr>
  </table>
</div>

---

## Équipe de Conception & Réalisation

Projet conçu et réalisé par l'équipe **Groupe n°5 — Smart Innovators** :
* **FADONOUGBO Anselme** — Concepteur & Développeur
* **HOUNKOKOE Trifène** — Concepteur & Développeur
* **KINDOMISSI Achille** — Concepteur & Développeur

* **Supervision & Écosystème** : 
  * Centre de formation Max_Adis (Édition 2026 — Vague 1)
  * Porto-Novo, Bénin

---

## Licence

Distribué sous licence MIT. Libre pour usage pédagogique et développement continu.
