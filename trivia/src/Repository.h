//
// Created by sebastien-manicon on 11/12/2025.
//

#ifndef TRIVIA_REPOSITORY_H
#define TRIVIA_REPOSITORY_H

//DB file
void standardInit(char *, int a);

void saveDB(char *, int a);

void loadDB(char *, int a);


class Repository {
public:
    virtual void standardInitdb(char *, int a) = 0;

    virtual void saveDBdb(char *, int a) = 0;

    virtual void loadDBdb(char *, int a) = 0;
};


class RepositoryImpl : public Repository {
public:
    void standardInitdb(char *a, int b) override {
        standardInit(a, b);
    }

    void saveDBdb(char *a, int b) override {
        saveDB(a, b);
    }

    void loadDBdb(char *a, int b) override {
        loadDB(a, b);
    }
};


void m(Repository *m) {
    m->standardInitdb("", 0);
    m->saveDBdb("", 0);
    m->loadDBdb("", 0);
}

void m() {
    m(new RepositoryImpl());
}

#endif //TRIVIA_REPOSITORY_H
