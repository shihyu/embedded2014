#ifndef LOADER_H_
#define LOADER_H_

#ifdef __cplusplus__
extern "C" {
#endif

/**
 * @defgroup elf_loader ELF Loader
 * @{
 */

/**
 * Protection flags of memory
 */
typedef enum {
	ELF_SEC_WRITE = 0x1, /*!< Enable for write */
	ELF_SEC_READ = 0x2, /*!< Enable for read */
	ELF_SEC_EXEC = 0x4, /*!< Enable for execution (instruction fetch) */
} ELFSecPerm_t;

/**
 * Exported symbol struct
 */
typedef struct {
	const char *name; /*!< Name of symbol */
	void *ptr; /*!< Pointer of symbol in memory */
} ELFSymbol_t;

/**
 * Environment for execution
 */
typedef struct {
	const ELFSymbol_t *exported; /*!< Pointer to exported symbols array */
	unsigned int exported_size; /*!< Elements on exported symbol array */
} ELFEnv_t;

/**
 * Execute ELF file from "path" with environment "env"
 * @param path Path to file to load
 * @param env Pointer to environment struct
 * @retval 0 On successful
 * @retval -1 On fail
 * @todo Error information
 */
extern int exec_elf(const char *path, const ELFEnv_t *env);

/** @} */

#ifdef __cplusplus__
}
#endif

#endif /* LOADER_H_ */
