#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "mappable.hpp"

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /**
   * @brief Classe astratta LinearContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori lineari che supportano l'accesso sequenziale agli elementi.
   */
  template <typename Data>
  class LinearContainer : virtual public PreOrderTraversableContainer<Data>,
                          virtual public PostOrderTraversableContainer<Data>
  {
  protected:
    using Container::size; /**< Dimensione del contenitore. */

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~LinearContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     *
     * @note L'assegnazione per copia non è supportata per evitare duplicazioni non controllate.
     */
    LinearContainer &operator=(const LinearContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     *
     * @note L'assegnazione per spostamento non è supportata per evitare stati incoerenti.
     */
    LinearContainer &operator=(LinearContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     */
    inline bool operator==(const LinearContainer &) const noexcept;

    /**
     * @brief Operatore di disuguaglianza.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     */
    inline bool operator!=(const LinearContainer &) const noexcept;

    /**
     * @brief Restituisce l'elemento all'indice specificato (in sola lettura).
     *
     * @param index Indice dell'elemento.
     * @return Riferimento costante all'elemento.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual const Data &operator[](const unsigned long int index) const = 0;

    /**
     * @brief Restituisce il primo elemento (in sola lettura).
     *
     * @return Riferimento costante al primo elemento.
     */
    virtual inline const Data &Front() const;

    /**
     * @brief Restituisce l'ultimo elemento (in sola lettura).
     *
     * @return Riferimento costante all'ultimo elemento.
     */
    virtual inline const Data &Back() const;

    /**
     * @brief Alias per la funzione di attraversamento.
     */
    using typename TraversableContainer<Data>::TraverseFun;

    /**
     * @brief Attraversa il contenitore.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    inline void Traverse(const TraverseFun func) const override;

    /**
     * @brief Attraversa il contenitore in pre-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    inline void PreOrderTraverse(const TraverseFun func) const override;

    /**
     * @brief Attraversa il contenitore in post-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    inline void PostOrderTraverse(const TraverseFun func) const override;
  };

  /**
   * @brief Classe astratta MutableLinearContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori lineari mutabili che supportano l'accesso e la modifica degli elementi.
   */
  template <typename Data>
  class MutableLinearContainer : virtual public LinearContainer<Data>,
                                 virtual public PreOrderMappableContainer<Data>,
                                 virtual public PostOrderMappableContainer<Data>
  {
  protected:
    using Container::size; /**< Dimensione del contenitore. */

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~MutableLinearContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    MutableLinearContainer &operator=(const MutableLinearContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    MutableLinearContainer &operator=(MutableLinearContainer &&) noexcept = delete;

    /**
     * @brief Restituisce l'elemento all'indice specificato (in lettura/scrittura).
     *
     * @param index Indice dell'elemento.
     * @return Riferimento all'elemento.
     *
     * @note Questa funzione deve essere implementata nelle classi derivate.
     */
    virtual Data &operator[](const unsigned long index) = 0;

    /**
     * @brief Restituisce il primo elemento (in lettura/scrittura).
     *
     * @return Riferimento al primo elemento.
     */
    virtual inline Data &Front();

    /**
     * @brief Restituisce l'ultimo elemento (in lettura/scrittura).
     *
     * @return Riferimento all'ultimo elemento.
     */
    virtual inline Data &Back();

    /**
     * @brief Rende visibili i metodi della classe base.
     */
    using LinearContainer<Data>::operator[];
    using LinearContainer<Data>::Front;
    using LinearContainer<Data>::Back;

    /**
     * @brief Alias per la funzione di mappatura.
     */
    using typename MappableContainer<Data>::MapFun;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore.
     *
     * @param func Funzione da applicare.
     */
    inline void Map(MapFun func) override;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore in pre-ordine.
     *
     * @param func Funzione da applicare.
     */
    inline void PreOrderMap(MapFun func) override;

    /**
     * @brief Applica una funzione a ogni elemento del contenitore in post-ordine.
     *
     * @param func Funzione da applicare.
     */
    inline void PostOrderMap(MapFun func) override;
  };

  /**
   * @brief Classe astratta SortableLinearContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori lineari ordinabili.
   */
  template <typename Data>
  class SortableLinearContainer : virtual public MutableLinearContainer<Data>
  {

  protected:
    using Container::size; /**< Dimensione del contenitore. */

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~SortableLinearContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    SortableLinearContainer &operator=(const SortableLinearContainer &) const = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    SortableLinearContainer &operator=(SortableLinearContainer &&) noexcept = delete;

    /**
     * @brief Ordina il contenitore.
     */
    inline void Sort() noexcept;

  protected:
    /**
     * @brief Esegue l'algoritmo di QuickSort.
     *
     * @param left Indice sinistro.
     * @param right Indice destro.
     */
    void QuickSort(unsigned long left, unsigned long right) noexcept;

    /**
     * @brief Partiziona il contenitore per QuickSort.
     *
     * @param left Indice sinistro.
     * @param right Indice destro.
     * @return Indice del pivot.
     */
    unsigned long Partition(unsigned long left, unsigned long right) noexcept;
  };

}

#include "linear.cpp"

#endif
