# PBDTest
## For a Particle by Digi Technical Interview, steps to reproduce.

Set up Google sheet. Set up an Apps Script with code from "googleAppScript".
    Replace the sheet name and sheet ID in lines 27 and 28 respectively

Set up Particle Integration to match docs "Particle Integration"
    Follow directions for newly set up Google Sheet and Apps Script as found Here: https://docs.particle.io/integrations/community-integrations/publish-to-google-sheets/

Flash firmware from boron to boron device
Flash firmware from photon to photon 2 device

Set up two Ledgers as Cloud to Device with device level permissions.
One is named cloud-to-boron, one is named cloud-to-photon, copy data as found in Boron Ledger file and Photon Ledger file respectively.

Set up logic function to match Logic Function file, replacing the ledger IDs with the newly created ones. Set up logic function trigger to match Logic Function Trigger file.

Please see the OnePager (either text only or PDF, they are the same content, different formats) and "particle arch diagram" for the Architecture diagram per project requirements.
