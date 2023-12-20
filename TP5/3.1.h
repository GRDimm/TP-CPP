class List{


    public:

        struct Element {
            double value;
            Element* prev = nullptr;
            Element* next = nullptr;
        };

        List();
        
        int NumElements();
        // Renvoyant le nombre d'éléments

        Element* Head();
        // Renvoyant un pointeur vers le premier élément de la liste (de type Element, cf plus bas), ou nullptr si la liste est vide.

        void Remove(Element* element);
        // Qui supprime un élément de la liste.

        Element* InsertNewElementAfter(double value, Element* position);
        // Qui crée un nouvel élément de la valeur donnée, et l'ajoute après un élément existant (position) de la liste, ou au début de la liste si position = nullptr. Elle renverra un pointeur vers l'élément crée.

        Element* Find(double d);
        // Qui renvoie un pointeur vers le premier élément de la liste dont la valeur est égale à d, ou nullptr si aucun élément n'est égal à d.

        void InsertListAfter(const List* other, Element* position);
        // Qui insère tout le contenu d'une autre liste après un élément donné de la liste courante (ou nullptr pour l'insérer au début).

    private:
        
        Element* head = nullptr;
        Element* tail = nullptr;
        int n = 0;
};