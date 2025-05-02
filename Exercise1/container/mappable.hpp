#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

#include <functional>
#include "traversable.hpp"

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /**
   * @brief Classe astratta MappableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano l'applicazione di una funzione a ogni elemento.
   */
  template <typename Data>
  class MappableContainer : virtual public TraversableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     *
     * @note Necessario per garantire la corretta distruzione degli oggetti derivati.
     */
    virtual ~MappableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     *
     * @note L'assegnazione per copia non è supportata per evitare duplicazioni non controllate.
     */
    MappableContainer &operator=(const MappableContainer &) noexcept = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     *
     * @note L'assegnazione per spostamento non è supportata per evitare stati incoerenti.
     */
    MappableContainer &operator=(MappableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     *
     * @note L'uguaglianza non è definita per questa classe astratta.
     */
    bool operator==(const MappableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     *
     * @note La disuguaglianza non è definita per questa classe astratta.
     */
    bool operator!=(const MappableContainer &) const noexcept = delete;

    /**
     * @brief Alias per la funzione di mappatura.
     */
    using MapFun = std::function<void(Data &)>;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore.
     *
     * @param fun Funzione da applicare.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual void Map(const MapFun fun) = 0;
  };

  /**
   * @brief Classe astratta PreOrderMappableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano la mappatura in pre-ordine.
   */
  template <typename Data>
  class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     *
     * @note Necessario per garantire la corretta distruzione degli oggetti derivati.
     */
    virtual ~PreOrderMappableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     *
     * @note L'assegnazione per copia non è supportata per evitare duplicazioni non controllate.
     */
    PreOrderMappableContainer &operator=(const PreOrderMappableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     *
     * @note L'assegnazione per spostamento non è supportata per evitare stati incoerenti.
     */
    PreOrderMappableContainer &operator=(PreOrderMappableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     *
     * @note L'uguaglianza non è definita per questa classe astratta.
     */
    bool operator==(const PreOrderMappableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     *
     * @note La disuguaglianza non è definita per questa classe astratta.
     */
    bool operator!=(const PreOrderMappableContainer &) const noexcept = delete;

    /**
     * @brief Alias per la funzione di mappatura.
     */
    using typename MappableContainer<Data>::MapFun;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore in pre-ordine.
     *
     * @param fun Funzione da applicare.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual void PreOrderMap(MapFun fun) = 0;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore (override).
     *
     * @param fun Funzione da applicare.
     */
    inline void Map(MapFun fun) override;
  };

  /**
   * @brief Classe astratta PostOrderMappableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano la mappatura in post-ordine.
   */
  template <typename Data>
  class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     *
     * @note Necessario per garantire la corretta distruzione degli oggetti derivati.
     */
    virtual ~PostOrderMappableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     *
     * @note L'assegnazione per copia non è supportata per evitare duplicazioni non controllate.
     */
    PostOrderMappableContainer &operator=(const PostOrderMappableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     *
     * @note L'assegnazione per spostamento non è supportata per evitare stati incoerenti.
     */
    PostOrderMappableContainer &operator=(PostOrderMappableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     *
     * @note L'uguaglianza non è definita per questa classe astratta.
     */
    bool operator==(const PostOrderMappableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     *
     * @note La disuguaglianza non è definita per questa classe astratta.
     */
    bool operator!=(const PostOrderMappableContainer &) const noexcept = delete;

    /**
     * @brief Alias per la funzione di mappatura.
     */
    using typename MappableContainer<Data>::MapFun;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore in post-ordine.
     *
     * @param fun Funzione da applicare.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual void PostOrderMap(const MapFun fun) = 0;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore (override).
     *
     * @param fun Funzione da applicare.
     */
    inline void Map(const MapFun fun) override;
  };

}

#include "mappable.cpp"

#endif
