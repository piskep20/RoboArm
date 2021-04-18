# RoboArm
Projekat baziran na Arduinu
> Sastoji se iz 6 servo motora kao i nekoliko delova odstampanih 3d stampacem, kao i IR prijemnikom
> Za IR prijmenik koji je koriscen u ovom projektu odgovara vecina klasicnih daljinskih upravljaca

**Povezivanje:**
![](https://i.imgur.com/sSWehXl.jpg)

Pre koriscenja ruke neophodno je podesiti **HEX-a** kodove dugmica koje ce te koristiti na vasem daljinskom upravljacu

Uputstvo za postavljanje HEX-a kodova:

Ostavicu kod za proveravanje HEX-a kodova dugmica u posebnom fajlu, neophodno je da skinete taj fajl na vas racnuar i prebacite program na vasu plocicu
![](https://i.imgur.com/LEdid54.png)

Kada ste prebacili program na vasu plocicu neophodno je da otvorite **Serial Monitor** i postavite **Baud rate na 9600**:
![](https://i.imgur.com/lwn6ub4.png)

Nakon toga pritisnite dugme za koje zelite da saznate HEX-a kod i prikazace vam se kao tekst u Service Monitoring prozorcicu
![](https://i.imgur.com/4ymVVVh.png)

Nakon sto to odradite potrebno je da kopirate taj HEX-a kod i definisete dugme pod imenom koje zelite
**Neophodno je da nakon definisanja dugmeta postavite 0x(pa HEX-a kod dugmeta)** kako bi dalje u programu, prijemnik mogao da procita primljeni signal
![](https://i.imgur.com/RE5OkVa.png)
![](https://i.imgur.com/R1oJH3X.png)
![](https://i.imgur.com/8a8UMxX.png)
![](https://i.imgur.com/BuhXbzs.png)

Nakon toga prebacite program na plocicu i testirajte.
