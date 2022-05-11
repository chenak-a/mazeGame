/**
* Implementation de la classe du Jeu
* \file   jeu.cpp
* \author Taylor et Alaa-Eddine
* \date   22 decembre 2021
* Créé le 3 decembre 2021
*/
#include "jeu.hpp"
#include <algorithm>
#include <sstream>

void Jeu::afficherMessageAccueil()
{
	cout << ">>>>>>>>>> INF1015 PROJET TROP COOL <<<<<<<<<<\n";
	cout << "> > > > > >  EDITION 2021 POLYMTL  < < < < < <\n\n";
}
void Jeu::jouer()
{
	string entreeUtilisateur;
	do
	{
		cout << "\n> ";
		getline(cin, entreeUtilisateur);

		auto [commande, entree] = gestionEntrees(entreeUtilisateur);

		if (entrees_.contains(commande))
			entrees_[commande](entree);

		else
			cout << "Je ne connais pas ça\n";

	} while (!estTermine_);
	cout << "\nPartie terminé, je m'en vais !";
}
void Jeu::associerObjets()
{
	pieces_["Entree"]->setObjet({ {{"porte"}, objets_["Une porte orange"].get()} });
	pieces_["Couloir"]->setObjet({ { {"cadre"}, objets_["Un cadre croche"].get()} });
	pieces_["Salle R"]->setObjet({ {{"piano","electrique" }, objets_["Un vieux piano electrique"].get()} });
	
	pieces_["Cuisine"]->setObjet(
		{ {{"assiette"}, objets_["Une assiette blanche"].get()},
		{{"poupee","russe"}, objets_["Une poupee russe"].get()},
		{{"boite"}, objets_["Une boite vide"].get()} }
	);
	
	pieces_["Chambre"]->setObjet(
		{ {{"interrupteur","lumiere"}, objets_["Un interrupteur de lumiere"].get() },
		{{"berceau"}, objets_["Un berceau simple"].get()} }
	);
	
	pieces_["Salon"]->setObjet({
		{ {"television"}, objets_["Une petite television"].get() },
		{ {"bouton"}, objets_["Un bouton rouge"].get() } });
}
void Jeu::associerEntreesUtilisateur()
{
	entrees_ = {
		{"n",[this](string word) {personnage_->deplacer(Direction_[word]); }},
		{"s",[this](string word) {personnage_->deplacer(Direction_[word]); }},
		{"o",[this](string word) {personnage_->deplacer(Direction_[word]); }},
		{"e",[this](string word) {personnage_->deplacer(Direction_[word]); }},
		{"look",[this](string word) {personnage_->regarderObjet(word); }},
		{"use",[this](string word) {if (word != "use" && !word.empty()) personnage_->utiliserObjet(word); else cout << "Veuillez entrer un objet\n"; }},
		{"exit",[this](string word) {estTermine_ = true; } }
	};
}
void Jeu::associerVoisins()
{
	pieces_["Entree"]->setVoisins({ {"Nord",pieces_["Couloir"].get()},{"Est", pieces_["Salon"].get()} });
	pieces_["Cuisine"]->setVoisins({ {"Sud", pieces_["Couloir"].get()} });
	pieces_["Couloir"]->setVoisins({ { "Nord", pieces_["Cuisine"].get() }, {"Ouest", pieces_["Chambre"].get()} ,{"Sud", pieces_["Entree"].get()},{"Est", pieces_["Salle R"].get()} });
	pieces_["Chambre"]->setVoisins("Est", pieces_["Couloir"].get());
	pieces_["Salon"]->setVoisins("Ouest", pieces_["Entree"].get());
	pieces_["Salle R"]->setVoisins("Ouest", pieces_["Couloir"].get());
}
void Jeu::creerObjets()
{
	// Entree
	objets_["Une porte orange"] = make_unique<Objet>("Une porte orange", "La porte est peinturé en orange. Elle a une petite poignée mauve.", "Vous ouvrer la porte pour y trouver un parapluie à l'intérieur.");
	// Cuisine
	objets_["Une assiette blanche"] = make_unique<Objet>("Une assiette blanche", "C'est une assiette blanche avec des motifs de fleurs. Elle est ronde.", "Vous manger la nourriture qui reste dans l'assiette.'");
	objets_["Une boite vide"] = make_unique<Objet>("Une boite vide", "C'est une boite de carton qui ne contient rien.", "Vous prenez la boite et l'ecrasez avec beaucoup de force.", true);
	objets_["Une poupee russe"] = make_unique<ObjetConteneur>("Une poupee russe", "C'est une poupée russe de bonne qualité.", "Vous ouvrez la poupée russe et elle est vide.", objets_["Une boite vide"].get(), "Vous ouvrez la poupée russe et une boite vide s'y trouve.");
	// Couloir
	objets_["Un cadre croche"] = make_unique<Objet>("Un cadre croche", "C'est une peinture à l'eau. Elle n'est pas bien réalisé.", "Vous bouger le cadre pour le remettre de niveau.");
	// Chambre
	objets_["Un interrupteur de lumiere"] = make_unique<Objet>("Un interrupteur de lumiere", "C'est un interrupteur qui commence à jaunir. Il est un peu cassé.", "Vous appuyer sur l'interrupteur, mais aucune lumière ne s'allume.");
	objets_["Un berceau simple"] = make_unique<Objet>("Un berceau simple", "Berceau sale qui n'a pas d'oreiller, seulement des draps.", "Vous vous coucher pour vous reposer un peu. Le berceau n'est pas confortable.");
	// Salon
	objets_["Un bouton rouge"] = make_unique<Objetclee>("Un bouton rouge", "C'est un bouton très usé. Il a souvent été appuyé.", "Le couloir est maintenant connecté à la Salle R.", static_cast<PieceCache*>(pieces_["Salle R"].get()));
	objets_["Une petite television"] = make_unique<Objet>("Une petite television", "C'est une vieille télévision cathodique. Elle est très profonde.", "Vous allumer la télévision et un un écran noir et blanc s'allume.");
	// Salle R
	objets_["Un vieux piano electrique"] = make_unique<Objet>("Un vieux piano electrique", "C'est un vieux piano avec 61 touches. Il n'est pas de très bonne qualité.", "Vous jouer quelques notes et un son terrible se fait entendre.");
}
void Jeu::creerPersonnage()
{
	personnage_ = make_unique<Personnage>(pieces_["Entree"].get());
}
void Jeu::creerPieces()
{
	pieces_["Entree"] = make_unique<Piece>("Entree", "Entree vaste avec des manteaux. Les murs sont verts. Il y a des crochets pour les manteaux.");
	pieces_["Cuisine"] = make_unique<Piece>("Cuisine", "Cuisine qui garde de la nourriture. Le plancher est collant. Il y a un lave-vaisselle et un four.");
	pieces_["Couloir"] = make_unique<Piece>("Couloir", "Couloir tres etroit. Plusieurs peintures sont accrochees aux murs. L'éclairage est faible.");
	pieces_["Chambre"] = make_unique<Piece>("Chambre", "Une petite chambre avec un lit. La fenêtre est ouverte. Un livre est sur la table de chevet.");
	pieces_["Salon"] = make_unique<Piece>("Salon", "Salon avec une television. Un tapis recouvre le plancher. Il y a une table entre au milieu de la piece.");
	pieces_["Salle R"] = make_unique<PieceCache>("Salle R", "Salle cachee super spéciale. Il n'y a rien de particulier dans la salle.");
}
pair<string, string> Jeu::gestionEntrees(string& entree)
{
	string command;
	for_each(entree.begin(), entree.end(), [](char& c) {c = static_cast<char>(::tolower(c)); });
	istringstream iss(entree);

	iss >> command;
	iss.ignore();
	entree = "";
	getline(iss, entree);

	entree = (entree.empty() || all_of(entree.begin(), entree.end(), isspace)) ? command : entree;
	return pair(command, entree);
}
void Jeu::demarrer()
{
	afficherMessageAccueil();
	personnage_->afficherChoix();
	jouer();
}