#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /**
   * @brief Classe astratta TestableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano la verifica dell'esistenza di un elemento.
   */
  template <typename Data>
  class TestableContainer : public virtual Container
  {

  public:
    /**
     * @brief Distruttore virtuale.
     *
     * @note Necessario per garantire la corretta distruzione degli oggetti derivati.
     */
    virtual ~TestableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     *
     * @note L'assegnazione per copia non è supportata per evitare duplicazioni non controllate.
     */
    TestableContainer &operator=(const TestableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     *
     * @note L'assegnazione per spostamento non è supportata per evitare stati incoerenti.
     */
    TestableContainer &operator=(TestableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     *
     * @note L'uguaglianza non è definita per questa classe astratta.
     */
    bool operator==(const TestableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     *
     * @note La disuguaglianza non è definita per questa classe astratta.
     */
    bool operator!=(const TestableContainer &) const noexcept = delete;

    /**
     * @brief Verifica se un elemento esiste nel contenitore.
     *
     * @param data Elemento da verificare.
     * @return true Se l'elemento esiste.
     * @return false Altrimenti.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual bool Exists(const Data &data) const noexcept = 0;
  };

}

#endif
