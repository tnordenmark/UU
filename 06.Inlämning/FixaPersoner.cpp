PersonLista TransaktionsLista::FixaPersoner() {

int antalKompisarTransaktion;
string* kompisar; //skall tilldelas pekare till array med kompisar
string transNamn;

PersonLista pl;


for (int i=0; i < antalTrans; i++) {

antalKompisarTransaktion= trans.haemta_ant_kompisar();

if (antalKompisarTransaktion>0) {

kompisar = trans.haemta_kompisar();
transNamn = trans.haemta_namn();

for (int j=0; j < antalKompisarTransaktion; j++) {

if (!pl.finnsPerson (kompisar[j])) {
Person temp( kompisar[j], liggerUteMed(kompisar[j]), aerSkyldig(kompisar[j]));
pl.laggTillEn(temp);
}

if (!pl.finnsPerson(transNamn) ){
Person temp( transNamn, liggerUteMed(transNamn), aerSkyldig(transNamn));
pl.laggTillEn(temp);
}
}
}
}

return pl;
}