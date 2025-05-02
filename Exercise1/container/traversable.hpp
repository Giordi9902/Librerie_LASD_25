#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>
#include "testable.hpp"

/* ************************************************************************** */

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /* ************************************************************************** */

  /**
   * @brief Classe astratta TraversableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano l'attraversamento degli elementi.
   */
  template <typename Data>
  class TraversableContainer : virtual public TestableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~TraversableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    TraversableContainer &operator=(const TraversableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    TraversableContainer &operator=(TraversableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     */
    bool operator==(const TraversableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     */
    bool operator!=(const TraversableContainer &) const noexcept = delete;

    /**
     * @brief Funzione di attraversamento degli elementi.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    using TraverseFun = std::function<void(const Data &)>;
    virtual void Traverse(const TraverseFun func) const = 0;

    /**
     * @brief Funzione di folding degli elementi.
     *
     * @tparam Accumulator Tipo dell'accumulatore.
     * @param func Funzione di folding.
     * @param acc Valore iniziale dell'accumulatore.
     * @return Valore finale dell'accumulatore.
     */
    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;
    template <typename Accumulator>
    inline Accumulator Fold(FoldFun<Accumulator> func, Accumulator acc) const;

    /**
     * @brief Verifica se un elemento esiste nel contenitore.
     *
     * @param data Elemento da verificare.
     * @return true Se l'elemento esiste.
     * @return false Altrimenti.
     */
    inline bool Exists(const Data &data) const noexcept override;
  };

  /* ************************************************************************** */

  /**
   * @brief Classe astratta PreOrderTraversableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano l'attraversamento in pre-ordine.
   */
  template <typename Data>
  class PreOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~PreOrderTraversableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    PreOrderTraversableContainer &operator=(const PreOrderTraversableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    PreOrderTraversableContainer &operator=(PreOrderTraversableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     */
    bool operator==(const PreOrderTraversableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     */
    bool operator!=(const PreOrderTraversableContainer &) const noexcept = delete;

    /**
     * @brief Funzione di attraversamento in pre-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PreOrderTraverse(const TraverseFun func) const = 0;

    /**
     * @brief Funzione di folding in pre-ordine.
     *
     * @tparam Accumulator Tipo dell'accumulatore.
     * @param func Funzione di folding.
     * @param acc Valore iniziale dell'accumulatore.
     * @return Valore finale dell'accumulatore.
     */
    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
    template <typename Accumulator>
    inline Accumulator PreOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;

    /**
     * @brief Attraversa il contenitore in pre-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    inline void Traverse(TraverseFun func) const override;
  };

  /* ************************************************************************** */

  /**
   * @brief Classe astratta PostOrderTraversableContainer.
   *
   * @tparam Data Tipo dei dati contenuti.
   *
   * @details Classe base per contenitori che supportano l'attraversamento in post-ordine.
   */
  template <typename Data>
  class PostOrderTraversableContainer : virtual public TraversableContainer<Data>
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~PostOrderTraversableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    PostOrderTraversableContainer &operator=(const PostOrderTraversableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    PostOrderTraversableContainer &operator=(PostOrderTraversableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     */
    bool operator==(const PostOrderTraversableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     */
    bool operator!=(const PostOrderTraversableContainer &) const noexcept = delete;

    /**
     * @brief Funzione di attraversamento in post-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    using typename TraversableContainer<Data>::TraverseFun;
    virtual void PostOrderTraverse(const TraverseFun func) const = 0;

    /**
     * @brief Funzione di folding in post-ordine.
     *
     * @tparam Accumulator Tipo dell'accumulatore.
     * @param func Funzione di folding.
     * @param acc Valore iniziale dell'accumulatore.
     * @return Valore finale dell'accumulatore.
     */
    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
    template <typename Accumulator>
    inline Accumulator PostOrderFold(FoldFun<Accumulator> func, Accumulator acc) const;

    /**
     * @brief Attraversa il contenitore in post-ordine.
     *
     * @param func Funzione da applicare a ogni elemento.
     */
    inline void Traverse(const TraverseFun func) const override;
  };

  /* ************************************************************************** */

}

#include "traversable.cpp"

#endif
