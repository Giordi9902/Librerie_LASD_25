#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /* ************************************************************************** */

  /**
   * @brief Classe astratta DictionaryContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano operazioni di inserimento, rimozione e ricerca.
   */
  template <typename Data>
  class DictionaryContainer : virtual public TestableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~DictionaryContainer() = default;

    /* ************************************************************************ */

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    DictionaryContainer &operator=(const DictionaryContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    DictionaryContainer &operator=(DictionaryContainer &&) noexcept = delete;

    /* ************************************************************************ */

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     */
    bool operator==(const DictionaryContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     */
    bool operator!=(const DictionaryContainer &) const noexcept = delete;

    /* ************************************************************************ */

    /**
     * @brief Inserisce un elemento nel contenitore.
     *
     * @param data Elemento da inserire.
     * @return true Se l'inserimento ha avuto successo.
     * @return false Altrimenti.
     */
    virtual bool Insert(const Data &data) = 0;

    /**
     * @brief Inserisce un elemento nel contenitore (versione per spostamento).
     *
     * @param data Elemento da inserire.
     * @return true Se l'inserimento ha avuto successo.
     * @return false Altrimenti.
     */
    virtual bool Insert(Data &&data) = 0;

    /**
     * @brief Rimuove un elemento dal contenitore.
     *
     * @param data Elemento da rimuovere.
     * @return true Se la rimozione ha avuto successo.
     * @return false Altrimenti.
     */
    virtual bool Remove(const Data &data) = 0;

    /**
     * @brief Inserisce tutti gli elementi di un contenitore traversabile.
     *
     * @param container Contenitore da cui inserire gli elementi.
     * @return true Se almeno un elemento è stato inserito.
     * @return false Altrimenti.
     */
    virtual inline bool InsertAll(const TraversableContainer<Data> &container);

    /**
     * @brief Inserisce tutti gli elementi di un contenitore mappabile (versione per spostamento).
     *
     * @param container Contenitore da cui inserire gli elementi.
     * @return true Se almeno un elemento è stato inserito.
     * @return false Altrimenti.
     */
    virtual inline bool InsertAll(MappableContainer<Data> &&container);

    /**
     * @brief Rimuove tutti gli elementi di un contenitore traversabile.
     *
     * @param container Contenitore da cui rimuovere gli elementi.
     * @return true Se almeno un elemento è stato rimosso.
     * @return false Altrimenti.
     */
    virtual inline bool RemoveAll(const TraversableContainer<Data> &container);

    /**
     * @brief Inserisce alcuni elementi di un contenitore traversabile.
     *
     * @param container Contenitore da cui inserire gli elementi.
     * @return true Se almeno un elemento è stato inserito.
     * @return false Altrimenti.
     */
    virtual inline bool InsertSome(const TraversableContainer<Data> &container);

    /**
     * @brief Inserisce alcuni elementi di un contenitore mappabile (versione per spostamento).
     *
     * @param container Contenitore da cui inserire gli elementi.
     * @return true Se almeno un elemento è stato inserito.
     * @return false Altrimenti.
     */
    virtual inline bool InsertSome(MappableContainer<Data> &&container);

    /**
     * @brief Rimuove alcuni elementi di un contenitore traversabile.
     *
     * @param container Contenitore da cui rimuovere gli elementi.
     * @return true Se almeno un elemento è stato rimosso.
     * @return false Altrimenti.
     */
    virtual inline bool RemoveSome(const TraversableContainer<Data> &container);
  };

  /**
   * @brief Classe astratta OrderedDictionaryContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori ordinati che supportano operazioni di ricerca e rimozione di elementi estremi o relativi.
   */
  template <typename Data>
  class OrderedDictionaryContainer : virtual public DictionaryContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~OrderedDictionaryContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    OrderedDictionaryContainer &operator=(const OrderedDictionaryContainer &) const = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    OrderedDictionaryContainer &operator=(OrderedDictionaryContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     */
    bool operator==(const OrderedDictionaryContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     */
    bool operator!=(const OrderedDictionaryContainer &) const noexcept = delete;

    /**
     * @brief Restituisce il minimo elemento del contenitore.
     *
     * @return Riferimento costante al minimo elemento.
     * @throws std::length_error Se il contenitore è vuoto.
     */
    virtual const Data &Min() const = 0;

    /**
     * @brief Restituisce e rimuove il minimo elemento del contenitore.
     *
     * @return Minimo elemento.
     * @throws std::length_error Se il contenitore è vuoto.
     */
    virtual Data MinNRemove() = 0;

    /**
     * @brief Rimuove il minimo elemento del contenitore.
     *
     * @throws std::length_error Se il contenitore è vuoto.
     */
    virtual void RemoveMin() = 0;

    // Simili commenti per Max, Predecessor, Successor, ecc.
  };

}

#include "dictionary.cpp"

#endif
