# RoboArm
Projekat baziran na Arduinu
Sastoji se iz 6 servo motora kao i nekoliko delova odstampanih 3d stampacem, kao i IR prijemnikom
Za IR prijmenik koji je koriscen u ovom projektu odgovara vecina klasicnih daljinskih upravljaca

Povezivanje:
//image

Pre koriscenja ruke neophodno je podesiti HEX-a kodove dugmica koje ce te koristiti na vasem daljinskom upravljacu

Uputstvo za postavljanje HEX-a kodova:

Na kraju koda za ruku, u komentaru je ostavljen ovaj kod:
//IMG

Kako biste saznali HEX-a kodove vasih dugmica neophodno je da uklonite oznake komentara sa tog koda
//IMG
zatim prebacite kod na vasu plocicu, otvorite Service Monitoring na Arduino IDE-u i podesite BAUD RATE na 9600
//IMG

Nakon toga pritisnite dugme za koje zelite da saznate HEX-a kod i prikazace vam se kao tekst u Service Monitoring prozorcicu
//IMG

Nakon sto to odradite potrebno je da kopirate taj HEX-a kod i definisete dugme pod imenom koje zelite
Neophodno je da nakon definisanja dugmeta postavite 0x(pa HEX-a kod dugmeta) kako bi dalje u programu, prijemnik mogao da procita primljeni signal
//IMG

Ukoliko ste promenili ime definisanog dugmica, neophodno je da promenite ime dugmica ovde takodje:

//IMG

Nakon toga prebacite program na plocicu i testirajte.
