#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

/**
 * @namespace lasd
 * @brief Namespace principale per la libreria LASD.
 */
namespace lasd
{

  /**
   * @brief Classe base astratta Container.
   *
   * @details Classe che rappresenta un contenitore generico con funzionalità di base.
   */
  class Container
  {

  protected:
    unsigned long size = 0; /**< Dimensione del contenitore. */

    /**
     * @brief Costruttore di default.
     */
    Container() = default;

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~Container() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    Container &operator=(const Container &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    Container &operator=(Container &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     */
    bool operator==(const Container &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     */
    bool operator!=(const Container &) const noexcept = delete;

    /**
     * @brief Verifica se il contenitore è vuoto.
     *
     * @return true Se il contenitore è vuoto.
     * @return false Altrimenti.
     */
    inline virtual bool Empty() const noexcept { return 0 == size; }

    /**
     * @brief Restituisce la dimensione del contenitore.
     *
     * @return Dimensione del contenitore.
     */
    inline virtual unsigned long Size() const noexcept { return size; }
  };

  /**
   * @brief Classe astratta ClearableContainer.
   *
   * @details Classe che rappresenta un contenitore che può essere svuotato.
   */
  class ClearableContainer : virtual public Container
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~ClearableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    ClearableContainer &operator=(const ClearableContainer &) = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    ClearableContainer &operator=(ClearableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     */
    bool operator==(const ClearableContainer &) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     */
    bool operator!=(const ClearableContainer &) const noexcept = delete;

    /**
     * @brief Metodo astratto per svuotare il contenitore.
     */
    virtual void Clear() = 0;
  };

  /**
   * @brief Classe astratta ResizableContainer.
   *
   * @details Classe che rappresenta un contenitore che può essere ridimensionato.
   */
  class ResizableContainer : virtual public ClearableContainer
  {

  public:
    /**
     * @brief Distruttore virtuale.
     */
    virtual ~ResizableContainer() = default;

    /**
     * @brief Operatore di assegnazione per copia eliminato.
     */
    ResizableContainer &operator=(const ResizableContainer &) noexcept = delete;

    /**
     * @brief Operatore di assegnazione per spostamento eliminato.
     */
    ResizableContainer &operator=(ResizableContainer &&) noexcept = delete;

    /**
     * @brief Operatore di uguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono uguali.
     * @return false Altrimenti.
     */
    bool operator==(const ResizableContainer &Ccon) const noexcept = delete;

    /**
     * @brief Operatore di disuguaglianza eliminato.
     *
     * @param other Contenitore da confrontare.
     * @return true Se i contenitori sono diversi.
     * @return false Altrimenti.
     */
    bool operator!=(const ResizableContainer &Ccon) const noexcept = delete;

    /**
     * @brief Metodo astratto per ridimensionare il contenitore.
     *
     * @param newSize Nuova dimensione del contenitore.
     */
    virtual void Resize(unsigned long newSize) = 0;

    /**
     * @brief Metodo per svuotare il contenitore.
     */
    void Clear() override { Resize(0); }
  };

}

/* ************************************************************************** */

#endif
